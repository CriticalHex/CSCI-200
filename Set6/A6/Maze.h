#ifndef MAZE_H
#define MAZE_H
#include "Room.h"
#include <SFML\Graphics.hpp>
#include <vector>

class Maze {
private:
  std::vector<std::vector<Room *>> _rooms;
  uint16_t _width, _height;
  sf::Vector2u _startPos, _endPos;
  sf::Vector2f _roomSize;

public:
  Maze();
  Maze(std::string);
  ~Maze();
  sf::Vector2f getRoomSize() const;
  sf::Vector2u getMazeSize() const;
  sf::Vector2u getStartPos() const;
  sf::Vector2u getEndPos() const;
  void draw(sf::RenderWindow &window);
  void create(std::string filename);
  void addAdjacencies();
};

#endif // MAZE_H