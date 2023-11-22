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
    for (Room room : row) {
      window.draw(room.rect);
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
      _rooms.push_back(vector<Room>());
      file >> row;
      for (int j = 0; j < _width; j++) {
        Room room;
        sf::RectangleShape rect = sf::RectangleShape(_roomSize);
        rect.setPosition(_roomSize.x * j, _roomSize.y * i);
        switch ((char)row[j]) {
        case '#': { // wall
          room.setFlags();
          rect.setFillColor(sf::Color::Black);
          break;
        }
        case '.': { // space
          room.setFlags(1);
          rect.setFillColor(sf::Color::White);
          break;
        }
        case 'S': { // start
          _startIndex = sf::Vector2u(j, i);
          room.setFlags(1, 1);
          rect.setFillColor(sf::Color::Green);
          break;
        }
        case 'E': { // end
          _endIndex = sf::Vector2u(j, i);
          room.setFlags(1, 0, 1);
          rect.setFillColor(sf::Color::Red);
          break;
        }
        default: {
          throw 0;
          break;
        }
        }
        room.setRect(rect);
        _rooms[i].push_back(room);
      }
      row = "";
    }
    file.close();
  } else {
    throw 0;
  }
}

Maze::~Maze() {
  for (auto row : _rooms) {
    row.clear();
  }
  _rooms.clear();
}