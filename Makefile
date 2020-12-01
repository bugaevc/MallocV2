CC=gcc
OBJDUMP=objdump
NM=nm
CFLAGS=-g -fno-omit-frame-pointer -Wall -Wextra -Wpedantic -std=gnu++11 -I /home/sergey/dev/lets-write-sync-primitives/src/ -x c++

OBJS := $(patsubst %.c, %.o, $(wildcard source/*.c))

all: debug

release: $(OBJS)
	$(CC) $(OBJS) -lm -lpthread -o alloc /home/sergey/dev/lets-write-sync-primitives/build-release/src/libsync_primitives.a
	#$(NM) alloc

debug: $(OBJS)
	$(CC) $(OBJS) -lm -lpthread -o alloc /home/sergey/dev/lets-write-sync-primitives/build-release/src/libsync_primitives.a
	#$(NM) alloc	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f source/*.o
	rm -f alloc

.PHONY: all clean
