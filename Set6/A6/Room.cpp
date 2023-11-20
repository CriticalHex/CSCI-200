#include "Room.h"

Room::Room(bool isTraversable, bool isStart, bool isEnd) {
  traversable = isTraversable;
  start = isStart;
  end = isEnd;
}

Room::~Room() {
  for (auto room : adjacentRooms) {
    delete room;
  }
}

void Room::setFlags(bool isTraversable, bool isStart, bool isEnd) {
  traversable = isTraversable;
  start = isStart;
  end = isEnd;
}

void Room::addAdjacent(Room *up, Room *down, Room *left, Room *right) {
  // clockwise rotation in the list
  adjacentRooms.push_back(up);
  adjacentRooms.push_back(right);
  adjacentRooms.push_back(down);
  adjacentRooms.push_back(left);
}

void Room::setRect(sf::RectangleShape rectangle) { rect = rectangle; }