#ifndef ROOM_H
#define ROOM_H
#include <SFML\Graphics.hpp>
#include <vector>

class Room {
private:
  bool _traversable, _start, _end, _visited = false;

public:
  Room *parent;
  sf::RectangleShape rect;
  std::vector<Room *> adjacentRooms;
  void addAdjacent(Room *up, Room *down, Room *left, Room *right);
  Room(bool isTraversable = 0, bool isStart = 0, bool isEnd = 0);
  ~Room();
  void setFlags(bool isTraversable = 0, bool isStart = 0, bool isEnd = 0);
  void setRect(sf::RectangleShape);
  bool isTraversable() const, isEnd() const, isStart() const, isVisited() const;
  void visit();
};

#endif