

# THE NAME OF YOUR EXECUTABLE
TARGET = L2C
# ALL CPP COMPILABLE IMPLEMENTATION FILES THAT MAKE UP THE PROJECT
SRC_FILES = main.cpp coordinate_conversion.h coordinate_conversion.cpp

# NO EDITS NEEDED BELOW THIS LINE

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic-errors
CXXFLAGS_DEBUG = -g

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm -f
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CXX) -o $@ $^

.cpp.o:
	@$(CXX) $(CXXFLAGS) $(CXXFLAGS_DEBUG) -o $@ -c $<

clean:
	@$(DEL) $(TARGET) $(OBJECTS)

.PHONY: all clean

# DEPENDENCIES
main.o: main.cpp