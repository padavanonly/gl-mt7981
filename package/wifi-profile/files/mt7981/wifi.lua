local M = {}

local scan = require "gl.scan"
local fs = require "oui.fs"
local uci = require "uci"
local reg = require "regulatory"

function M.devices(band)
    local c = uci.cursor()
    local devices = {}

    c:foreach("wireless", "wifi-device", function(s)
        if s.disabled == "1" then return end

        if band == "2g" then
            if s.hwmode:match("a") then return end
        elseif band == "5g" then
            if not s.hwmode:match("a") then return end
        end

        local sid = s[".name"]
        local dev = sid

        if sid == "mt7615e5" or sid == "mt7628" then
            dev = "ra0"
        elseif sid == "mt7615e2" then
            dev = "rax0"
        end

        devices[sid] = dev
    end)

    return devices
end

M.fix_sta_ifname = function()
    local c = uci.cursor()
    local device = c:get("wireless", "sta", "device")
    local ifname

    if device == "mt7615e2" then
        ifname = "apclix0"
    elseif device == "mt7615e5" or device == "mt7628" then
        ifname = "apcli0"
    else
        ifname = "wlan-sta"
    end

    c:set("wireless", "sta", "ifname", ifname)

    c:commit("wireless")
end

M.connect = function(params)
    local c = uci.cursor()

    local device = params.device
    local ssid = params.ssid
    local encryption = params.encryption
    local key = params.key
    local bssid = params.bssid
    local band = params.band
    local wds = params.wds

    if type(ssid) ~= "string" then
        error("ssid required")
    end

    c:delete("wireless", "sta")

    c:set("wireless", "sta", "wifi-iface")
    c:set("wireless", "sta", "mode", "sta")
    c:set("wireless", "sta", "device", device or "")
    c:set("wireless", "sta", "ssid", ssid)
    c:set("wireless", "sta", "bssid", bssid or "")
    c:set("wireless", "sta", "band", band or "")
    c:set("wireless", "sta", "encryption", encryption or "none")
    c:set("wireless", "sta", "key", key or "")

    if wds then
        c:set("wireless", "sta", "network", "lan")
        c:set("wireless", "sta", "wds", "1")
    else
        c:set("wireless", "sta", "network", "wwan")
    end

    c:commit("wireless")

    M.fix_sta_ifname()
end

local function mtk_scan_dump(ifname)
    local iwpriv = require 'iwpriv'
    local index = 0
    local survey = {}
    local total

    while true do
        local data = iwpriv.get_site_survey2(ifname, index) or ""

        total = tonumber(data:match("Total=(%d+)"))

        if not total then
            break
        end

        data = data:sub((data:find("No")))

        local widths = {}

        widths.ch = {data:find("Ch "), 3}
        widths.ssid = {data:find("SSID "), 32}
        widths.bssid = {data:find("BSSID "), 17}
        widths.security = {data:find("Security "), 22}
        widths.signal = {data:find("Siganl"), 3}
        widths.wmode = {data:find("W%-Mode"), 11}
        widths.nt = {data:find("NT"), 2}
        widths.ssid_len = {data:find("SSID_Len"), 2}

        data = data:sub((data:find("%d+")))

        local function get_field(line, width, no_trim)
            local value = line:sub(width[1], width[1] + width[2])
            if no_trim then
                return value
            end

            return value:match("%S+")
        end

        for line in data:gmatch("[^\n]+") do
            index = tonumber(line:match("%d+"))
            local channel = tonumber(get_field(line, widths.ch))
            local ssid = get_field(line, widths.ssid, true)
            local bssid = get_field(line, widths.bssid)
            local security = get_field(line, widths.security)
            local signal = tonumber(get_field(line, widths.signal))
            --local wmode = get_field(line, widths.wmode)
            local nt = get_field(line, widths.nt)
            local ssid_len = tonumber(get_field(line, widths.ssid_len))

            local authmode, encrypttype = security:match("([%w-]+)/?(%w*)")

            if not encrypttype then
                encrypttype = "NONE"
            end

            if nt == "In" and (authmode:match("PSK") or authmode == "OPEN") then
                local auth_suites = {}
                local encryption = {
                    enabled = false
                }

                if authmode ~= "OPEN" then
                    encryption.enabled = true

                    if authmode:match("WPAPSK") or authmode:match("WPA2PSK") then
                        auth_suites[#auth_suites + 1] = "PSK"
                    end

                    if authmode:match("WPA3PSK") then
                        auth_suites[#auth_suites + 1] = "SAE"
                    end
                end

                encryption.auth_suites = auth_suites
                encryption.description = security

                survey[#survey + 1] = {
                    bssid = bssid,
                    ssid = ssid:sub(0, ssid_len),
                    channel = channel,
                    signal = signal,
                    encryption = encryption,
                    authmode = authmode,
                    encrypttype = encrypttype,
                    mode = "Master"
                }
            end
        end

        if index + 1 == total then
            break
        end
    end

    return survey
end

M.scan_trigger = function(ifname, ssid)
    if ifname:match("^ra") or ifname:match("^apcli") then
        local iwpriv = require 'iwpriv'
        iwpriv.set(ifname, "SiteSurvey", ssid)
        return true
    else
        return scan.scan_trigger(ifname, ssid)
    end
end

M.scan_dump = function(ifname)
    if ifname:match("^ra") or ifname:match("^apcli") then
        return mtk_scan_dump(ifname)
    else
        return scan.scan_dump(ifname)
    end
end

M.disable_guest_during_scan_wifi = function()
    return fs.access("/lib/modules/4.4.60/ath11k.ko")
end

local function reg_match(channel, freq, ranges, country)
    if country == "US" and channel > 11 and channel < 36 then
        return false
    end

    for _, range in ipairs(ranges) do
        if range.power > 10 then
            if freq > range.start and freq < range["end"] then
                return true, range.dfs
            end
        end
    end
end

M.get_channel_list = function(country)
    local ranges = reg.get(country)

    local chan2g_freq = {
        { 1, 2412 },
        { 2, 2417 },
        { 3, 2422 },
        { 4, 2427 },
        { 5, 2432 },
        { 6, 2437 },
        { 7, 2442 },
        { 8, 2447 },
        { 9, 2452 },
        { 10, 2457 },
        { 11, 2462 },
        { 12, 2467 },
        { 13, 2472 }
    }

    local chan5g_freq = {
        { 36, 5180 },
        { 40, 5200 },
        { 44, 5220 },
        { 48, 5240 },

        { 52, 5260 },
        { 56, 5280 },
        { 60, 5300 },
        { 64, 5320 },

        { 100, 5500 },
        { 104, 5520 },
        { 108, 5540 },
        { 112, 5560 },
        { 116, 5580 },
        { 120, 5600 },
        { 124, 5620 },
        { 128, 5640 },
        { 132, 5660 },
        { 136, 5680 },
        { 140, 5700 },
        { 144, 5720 },

        { 149, 5745 },
        { 153, 5765 },
        { 157, 5785 },
        { 161, 5805 },
        { 165, 5825 }
    }

    local chan2g = {}
    local chan5g = {}

    for _, ch in ipairs(chan2g_freq) do
        if reg_match(ch[1], ch[2], ranges, country) then
            chan2g[#chan2g + 1] = { channel = ch[1], dfs = false }
        end
    end

    for _, ch in ipairs(chan5g_freq) do
        local ok, dfs = reg_match(ch[1], ch[2], ranges, country)
        if ok then
            chan5g[#chan5g + 1] = { channel = ch[1], dfs = dfs }
        end
    end

    return chan2g, chan5g
end

return M
