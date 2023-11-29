#include "Room.h"

Room::Room(bool traversable, bool start, bool end) {
  _traversable = traversable;
  _start = start;
  _end = end;
  parent = nullptr;
}

Room::~Room() {
  for (auto room : adjacentRooms) {
    delete room;
  }
  adjacentRooms.clear();
}

void Room::setFlags(bool traversable, bool start, bool end) {
  _traversable = traversable;
  _start = start;
  _end = end;
}

void Room::addAdjacent(Room *up, Room *down, Room *left, Room *right) {
  // clockwise rotation in the list
  adjacentRooms.push_back(left);
  adjacentRooms.push_back(down);
  adjacentRooms.push_back(right);
  adjacentRooms.push_back(up);
}

void Room::setRect(sf::RectangleShape rectangle) { rect = rectangle; }

bool Room::isTraversable() const { return _traversable; }

bool Room::isStart() const { return _start; }

bool Room::isEnd() const { return _end; }

bool Room::isVisited() const { return _visited; }

void Room::visit() {
  _visited = true;
  if (!_start && !_end)
    rect.setFillColor(sf::Color::Magenta);
}