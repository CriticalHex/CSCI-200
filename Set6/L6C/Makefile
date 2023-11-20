TARGET = L6C.exe
SRC_FILES = main.cpp Maze.cpp Room.cpp

OBJECTS = $(SRC_FILES:.cpp=.o)

INCLUDE_PATH = -I"C:\mingw64\include"

LIBS = -lsfml-graphics -lsfml-window -lsfml-system
LIB_PATH = -L"C:\mingw64\include\libs"
CXX = g++

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CXX) -o $@ $^ $(LIB_PATH) $(LIBS)

%.o: %.cpp
	@$(CXX) -c $< -o $@ $(INCLUDE_PATH)

clean:
	@$(RM) $(OBJECTS) $(TARGET)

run:
	@$(TARGET)

.PHONY: clean run

main.o: main.cpp Maze.o Room.o
Maze.o: Maze.cpp
Room.o: Room.cpp