detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
ifeq ($(detected_OS),Darwin)  # Mac OS X
	CC := clang++
	CFLAGS := -std=c++14 -stdlib=libc++
endif
ifeq ($(detected_OS),Linux)
	CC := g++
	CFLAGS := -std=c++17 -pthread
endif


SRCS := $(wildcard *.cc)
OBJS := $(patsubst %.cc,%.out,$(SRCS))

all: $(OBJS)

%.out: %.cc
	$(CC) $(CFLAGS) -o target/$@  $<
clean:
	rm   target/*.out

.PHONY: all clean

