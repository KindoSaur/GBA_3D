#
# Makefile for first.gba
#
DEVKITARM := D:/Libraries/DevKitPro/devkitARM
PATH := $(DEVKITARM)/bin:$(PATH)

# --- Project details -------------------------------------------------

PROJ    := main
TARGET  := $(PROJ)
BUILD_DIR := build

SOURCES := $(wildcard source/*.cpp)
HEADERS := $(wildcard include/*.hpp)

OBJS    := $(SOURCES:source/%.cpp=$(BUILD_DIR)/%.o)

# --- Build defines ---------------------------------------------------

PREFIX  := arm-none-eabi-
CXX     := $(PREFIX)g++
LD      := $(PREFIX)gcc
OBJCOPY := $(PREFIX)objcopy

ARCH    := -mthumb-interwork -mthumb
SPECS   := -specs=gba.specs

CXXFLAGS  := $(ARCH) -O2 -Wall -fno-strict-aliasing -Iinclude
LDFLAGS := $(ARCH) $(SPECS)


.PHONY : make clean

# --- Build -----------------------------------------------------------
# Build process starts here!
make: $(BUILD_DIR)/$(TARGET).gba

# Strip and fix header (step 3,4)
$(BUILD_DIR)/$(TARGET).gba : $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -v -O binary $< $@
	-@D:/Libraries/DevKitPro/tools/bin/gbafix $@

# Link (step 2)
$(BUILD_DIR)/$(TARGET).elf : $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

# Compile (step 1)
$(BUILD_DIR)/%.o : source/%.cpp $(HEADERS)
	$(CXX) -c $< $(CXXFLAGS) -o $@

# --- Clean -----------------------------------------------------------
clean : 
	-del -f /q $(BUILD_DIR)\*.gba $(BUILD_DIR)\*.elf $(BUILD_DIR)\*.o

#EOF