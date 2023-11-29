#include "Maze.h"
#include <fstream>

using namespace std;

Maze::Maze(string filename) {
  _roomSize = sf::Vector2f(50, 50);
  _width = _height = 0;
  create(filename);
}

Maze::Maze() {
  _roomSize = sf::Vector2f(50, 50);
  _width = _height = 0;
}

sf::Vector2f Maze::getRoomSize() const { return _roomSize; }

sf::Vector2u Maze::getMazeSize() const {
  return sf::Vector2u(_roomSize.x * _width, _roomSize.y * _height);
}

void Maze::draw(sf::RenderWindow &window) {
  for (auto row : _rooms) {
    for (Room *room : row) {
      window.draw(room->rect);
    }
  }
}

void Maze::create(string filename) {
  _rooms.clear();
  ifstream file(filename);
  if (!file.fail()) {
    file >> _height >> _width;
    string row;
    for (int i = 0; i < _height; i++) {
      _rooms.push_back(vector<Room *>());
      file >> row;
      for (int j = 0; j < _width; j++) {
        Room *room = new Room();
        sf::RectangleShape rect = sf::RectangleShape(_roomSize);
        rect.setPosition(_roomSize.x * j, _roomSize.y * i);
        switch ((char)row[j]) {
        case '#': { // wall
          room->setFlags();
          rect.setFillColor(sf::Color::Black);
          break;
        }
        case '.': { // space
          room->setFlags(1);
          rect.setFillColor(sf::Color::White);
          break;
        }
        case 'S': { // start
          _start = room;
          room->setFlags(1, 1);
          rect.setFillColor(sf::Color::Green);
          break;
        }
        case 'E': { // end
          _end = room;
          room->setFlags(1, 0, 1);
          rect.setFillColor(sf::Color::Red);
          break;
        }
        default: {
          throw 0;
          break;
        }
        }
        room->setRect(rect);
        _rooms[i].push_back(room);
      }
      row = "";
    }
    file.close();
  } else {
    throw 0;
  }
}

void Maze::addAdjacencies() {
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      Room *up = (i - 1 >= 0) ? _rooms[i - 1][j] : new Room();
      Room *down = (i + 1 < _height) ? _rooms[i + 1][j] : new Room();
      Room *left = (j - 1 >= 0) ? _rooms[i][j - 1] : new Room();
      Room *right = (j + 1 < _width) ? _rooms[i][j + 1] : new Room();
      _rooms[i][j]->addAdjacent(up, down, left, right);
    }
  }
}

Room *Maze::getStartRoom() const { return _start; }
Room *Maze::getEndRoom() const { return _end; }

Maze::~Maze() {
  for (auto row : _rooms) {
    for (Room *room : row) {
      delete room;
    }
    row.clear();
  }
  _rooms.clear();
}