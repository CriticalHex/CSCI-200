#include "MazeSolver.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  MazeSolver solver(argc, argv);
  sf::RenderWindow window(
      sf::VideoMode(solver.maze.getMazeSize().x, solver.maze.getMazeSize().y),
      "Maze Solver.maze!", sf::Style::None);
  window.setFramerateLimit(20);
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
    if (!solver.isSolved())
      solver.solve();
    window.clear();
    solver.maze.draw(window);
    window.display();
  }
  return 0;
}