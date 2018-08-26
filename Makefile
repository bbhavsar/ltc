detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
ifeq ($(detected_OS),Darwin)  # Mac OS X
	CC := clang++
	CFLAGS := -std=c++11 -stdlib=libc++
endif
ifeq ($(detected_OS),Linux)
	CC := g++
	CFLAGS := -std=c++11
endif


SRCS := $(wildcard *.cc)
OBJS := $(patsubst %.cc,%.out,$(SRCS))

all: $(OBJS)

%.out: %.cc
	$(CC) $(CFLAGS) -o $@  $<
clean:
	rm -rf  *.out

.PHONY: all clean

