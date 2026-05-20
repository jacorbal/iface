# Copyright (c) 2019-2026, J. A. Corbal
#
# Makefile

SHELL = /bin/bash


## Directories
PWD   = $(CURDIR)
I_DIR = $(PWD)/include
S_DIR = $(PWD)/src
L_DIR = $(PWD)/lib
O_DIR = $(PWD)/obj
B_DIR = $(PWD)/bin


## Compiler & linker opts.
CC      = cc
CSTD    = c99
OPTLVL  = 3 #0:debug; 1:optimize; 2:optimize more; 3:optimize even more
CFLAGSX = -D_DEFAULT_SOURCE
CFLAGSW = -Wall -Werror -Wextra
CCFLAGS = -I $(I_DIR) -std=$(CSTD) $(CFLAGSW) $(CFLAGSX)
LDFLAGS = -L $(L_DIR)

# Use `make DEBUG=1` to add debugging information, symbol table, etc.
# When debugging the optimization level will be shut down in order to
# get better results
DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CCFLAGS += -DDEBUG -g -ggdb -O0
else
	CCFLAGS += -DNDEBUG -O$(OPTLVL)
	LDFLAGS += -s
endif


## Makefile opts.
SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .h .c .o


## Files options
TARGET = $(B_DIR)/main
OBJS = $(patsubst $(S_DIR)/%.c, $(O_DIR)/%.o, $(wildcard $(S_DIR)/*.c))
ARGS ?=

# Options
all: makedirs $(TARGET)
	@echo "Done"

makedirs:
	@mkdir -p $(B_DIR) $(O_DIR)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(O_DIR)/%.o: $(S_DIR)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean-obj:
	@rm -f $(OBJS)
	@rmdir -p --ignore-fail-on-non-empty $(O_DIR) 2>/dev/null || true

clean-bin:
	@rm -f $(TARGET)
	@rmdir -p --ignore-fail-on-non-empty $(B_DIR) 2>/dev/null || true

clean: clean-obj clean-bin

clean-all: clean

debug:
	@make hard DEBUG=1

run:
	$(TARGET) $(ARGS)

hard: clean all

hard-run: clean all run

help:
	@echo "Type:"
	@echo "  'make all'......................... Build project"
	@echo "  'make run'................ Run binary (if exists)"
	@echo "  'make clean-obj'.............. Clean object files"
	@echo "  'make clean'....... Clean binary and object files"
	@echo "  'make debug'................Compile in DEBUG mode"
	@echo "  'make hard'...................... Clean and build"
	@echo ""
	@echo " Binary will be placed in '$(TARGET)'"


## Phony targets
.PHONY: makedirs all clean-obj clean-all clean run hard hard-run help

