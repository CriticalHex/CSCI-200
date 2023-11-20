#include "Room.h"

Room::Room() {}

Room::~Room() {}

void Room::setFlags(bool isTraversable, bool isStart, bool isEnd) {
  traversable = isTraversable;
  start = isStart;
  end = isEnd;
}

void Room::setRect(sf::RectangleShape rectangle) { rect = rectangle; }