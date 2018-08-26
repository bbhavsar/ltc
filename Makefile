detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
ifeq ($(detected_OS),Darwin)  # Mac OS X
	CC := clang++
endif
ifeq ($(detected_OS),Linux)
	CC := g++
endif

CFLAGS := -std=c++11 -stdlib=libc++
TARGET := ltc

SRCS := $(wildcard *.cc)
OBJS := $(patsubst %.cc,%.out,$(SRCS))

all: $(OBJS)

%.out: %.cc
	$(CC) $(CFLAGS) -o $@  $<
clean:
	rm -rf $(TARGET) *.out

.PHONY: all clean

