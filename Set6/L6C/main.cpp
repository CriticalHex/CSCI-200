#include "Maze.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  Maze maze;
  if (argc > 1) {
    maze.create(string(*(argv + 1)));
  } else {
    string filename;
    cout << "Enter a filename: ";
    cin >> filename;
    maze.create(filename);
  }
  sf::RenderWindow window(
      sf::VideoMode(maze.getMazeSize().x, maze.getMazeSize().y), "Maze!",
      sf::Style::None);
  sf::Event event;
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      if (event.type == event.Closed) {
        window.close();
      }
      if (event.type == event.KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
          window.close();
        }
      }
    }
    window.clear();
    maze.draw(window);
    window.display();
  }
  return 0;
}