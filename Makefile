#
# **************************************************************
# *                Simple C++ Makefile Template                *
# *                                                            *
# * Author: Arash Partow (2003)                                *
# * URL: http://www.partow.net/programming/makefile/index.html *
# *                                                            *
# * Copyright notice:                                          *
# * Free use of this C++ Makefile template is permitted under  *
# * the guidelines and in accordance with the the MIT License  *
# * http://www.opensource.org/licenses/MIT                     *
# *                                                            *
# **************************************************************
#

CXX      ?= g++
CXXFLAGS ?= -std=c++20 -pedantic-errors -Wall -Wextra #-Werror
LDFLAGS  ?= -L/usr/lib -lstdc++ -lm -lncurses
BUILD    ?= ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)
TARGET   ?= tirecenter
INCLUDE  ?= -Iclasses/
SRC      ?=                      \
   $(wildcard src/*.cpp)         \
   #$(wildcard src/module1/*.cpp) \
   #$(wildcard src/module2/*.cpp) \

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES := \
	$(OBJECTS:.o=.d)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info run

compile_commands:


build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g3
debug: all


release: CXXFLAGS += -O2
release: all

run: all
	$(APP_DIR)/$(TARGET)

launch:
	$(APP_DIR)/$(TARGET)

gdb: debug
	@gdb $(APP_DIR)/$(TARGET)

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

info:
	@echo "[*] Compiler:        ${CXX}         "
	@echo "[*] Compiler flags:  ${CXXFLAGS}    "
	@echo "[*] Linker flags:    ${LDFLAGS}     "
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"
