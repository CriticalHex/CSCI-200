TARGET = A1
SRC_FILES = main.cpp

# keep
CXX = g++
CFLAGS = -Wall -g -Werror -std=c++11
OBJECTS = $(SRC_FILES:.cpp=.o)
ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

$(TARGET): $(OBJECTS)
	@$(CXX) -o $@ $^

%.o: %.cpp
	@$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	@$(DEL) $(TARGET) $(OBJECTS)