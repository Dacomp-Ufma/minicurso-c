FLAGS   = -O0 -g -DMUNDIAL_PALMEIRAS=0
SOURCE  = $(wildcard src/*.c)
BUILD   = build
INCLUDE = include

PLATFORM = windows


ifeq ($(PLATFORM), windows)
FLAGS += -DWINDOWS=1
else
FLAGS += -DWINDOWS=0
endif

$(BUILD)/debug: $(SOURCE)
	$(CC) -I$(INCLUDE) $(FLAGS) -o $@ $^

all: build/debug