#ifndef ROOM_H
#define ROOM_H
#include <SFML\Graphics.hpp>

class Room {
private:
public:
  bool traversable, start, end;
  sf::RectangleShape rect;
  Room();
  ~Room();
  void setFlags(bool = 0, bool = 0, bool = 0);
  void setRect(sf::RectangleShape);
};

#endif