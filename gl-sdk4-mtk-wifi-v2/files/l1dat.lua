#!/usr/bin/lua

-- Constant Definition
local FW_PATH = "/lib/firmware/"
local MTD_PATH = "/dev/"
local MTD_TABLE = "/proc/mtd"
local E2P_PART_NAME = "Factory"
local E2P_FILE_NAME = "e2p"


function show_usage()
    print("Usage: l1dat genconfig | dbg | idx2if idx | if2zone ifname | if2dat ifname | zone2if zone | if2dbdcidx ifname")
end

function print_err(msg)
    io.stderr:write("[ERR][l1dat] "..msg)
end

if not pcall(require, "l1dat_parser") then
    if arg[1] == "dbg" then
        print_err("Load l1dat_parser module failed\n")
    end
    return
end

local l1parser = require("l1dat_parser")
local l1dat = l1parser.load_l1_profile(l1parser.L1_DAT_PATH)

if not l1dat then
    if arg[1] == "dbg" then
        print_err("l1profile.dat is ivalid\n")
    end
    return
end

function read_pipe(pipe)
    local fp = io.popen(pipe)
    local txt =  fp:read("*a")
    fp:close()
    return txt
end

function eeprom_extract(part, offset, size, bin_name)
    local part_name = part or E2P_PART_NAME
    local dump_name = bin_name or E2P_FILE_NAME

    if not offset or not size or tonumber(offset) < 0 or tonumber(size) < 0 then
        print_err("Invalid offset or size value")
        return
    end
    local offset_decimal = string.format("%d", offset)
    local size_decimal   = string.format("%d", size)

    local cmd = "cat "..MTD_TABLE.." | grep "..part_name
    local mtd = read_pipe(cmd)
    if not mtd or mtd == "" then
        print_err("mtd partition "..part_name.." not found")
        return
    end

    cmd = "[ -e "..FW_PATH.." ] || mkdir "..FW_PATH
    os.execute(cmd)

    local mtd_node = "/dev/"..string.match(mtd, "(mtd[%d]+)")
    cmd = "dd if="..mtd_node.." of="..FW_PATH..dump_name.." bs=1 skip="..offset_decimal.." count="..size_decimal.." seek="..offset_decimal.." conv=notrunc 2>/dev/null"
    os.execute(cmd)
end

local action0 = {
    ["dbg"] = function()
        show_usage()
    end,

    ["genconfig"] = function()
        local seen = {}
        local dridx = l1parser.DEV_RINDEX
        local cmd = ""
        local dir = ""
        for name, dev in pairs(l1dat[dridx]) do
            if not seen[dev] then
                seen[dev] = true
                dir = string.match(dev["profile_path"], "^(.+)/")
                --print("mkdir -p "..dir)
                os.execute("mkdir -p "..dir)
                cmd = "ralink_init gen "..dev["nvram_zone"].." "..dev["profile_path"]
                --print(cmd)
                os.execute(cmd)

                eeprom_extract(E2P_PART_NAME, dev.EEPROM_offset, dev.EEPROM_size, dev.EEPROM_name)
            end
        end
    end,

    ["if2zone"] = function(ifname)
        if not ifname then return end

        local zone = l1parser.l1_ifname_to_zone(ifname) or ""
        print(zone);
    end,

    ["if2dat"] = function(ifname)
        if not ifname then return end

        local dat_path = l1parser.l1_ifname_to_datpath(ifname) or ""
        print(dat_path)
    end,

    ["zone2if"] = function(zone)
        if not zone then return end

        local main_if, ext_if, apcli, wds, mesh = l1parser.l1_zone_to_ifname(zone)

        if main_if then
            print(main_if.." "..ext_if.." "..apcli.." "..wds.." "..mesh)
        end
    end,

    ["idx2if"] = function(idx)
        if not idx then return end

        idx = tonumber(idx)

        local band_num = l1parser.MAX_NUM_DBDC_BAND
        local dbdc_if
        local count = 0
        for k, v in pairs(l1dat) do
            -- check if last dbdc exists
            dbdc_if = l1parser.token_get(v.main_ifname, band_num, nil)
            if dbdc_if then
                count = count + band_num;
            else
                count = count + 1
            end

            if not dbdc_if and count == idx then
                print(v.main_ifname)

                break
            end

            if count >= idx then -- dbdc case
                local token_num = band_num - ( count - idx )
                print(l1parser.token_get(v.main_ifname, token_num, nil))

                break
            end
        end
    end,

    ["if2dbdcidx"] = function(ifname)
        if not ifname then return end

        local ridx = l1parser.IF_RINDEX

        if not l1dat[ridx][ifname] then return end

        print(l1dat[ridx][ifname]["subidx"] or "0")
    end
}

if #arg == 0 then
    show_usage()
    return
end

if action0[arg[1]] then
    if #arg == 1 then
        --print("#arg == 1", arg[1])
        action0[arg[1]]()
    elseif #arg == 2 then
        --print("#arg == 1", arg[1], arg[2])
        action0[arg[1]](arg[2])
    end
else
    print_err("invalid arg \""..arg[1].."\"\n");
end
