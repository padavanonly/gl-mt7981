OBJS = rtmpiapp.o mt_iapp_util.o

# If you want to debug daemon, uncomment following line
# CFLAGS += -ggdb3 -DDBG
LDFLAGS += -lpthread

mtkiappd: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) 
clean:
	rm -f core *.o mtkiappd
