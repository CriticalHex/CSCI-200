#include "MazeSolver.h"
#include <iostream>

using namespace std;

MazeSolver::MazeSolver(int argc, char **argv) {
  if (argc > 1) {
    maze.create(string(*(argv + 1)));
    if (argc > 2) {
      _method = string(*(argv + 2));
    }
  } else {
    string filename;
    cout << "Enter a filename: ";
    cin >> filename;
    maze.create(filename);
  }
  maze.addAdjacencies();
  _queue.push(maze.getStartRoom());
  _stack.push(maze.getStartRoom());
  maze.getStartRoom()->visited = true;
  if (_method == "") {
    cout << "How would you like to solve the maze? ('BFS'/'DFS'): ";
    cin >> _method;
  }
}

MazeSolver::~MazeSolver() {}

void MazeSolver::solve() {
  if (_method == "BFS")
    breadthFirstSearch();
  else if (_method == "DFS")
    depthFirstSearch();
  if (_solved)
    markUncheckedRooms();
}

void MazeSolver::breadthFirstSearch() {
  for (auto room : _queue.front()->adjacentRooms) {
    if (room->traversable) {
      if (room->end) {
        room->visited = true;
        _solved = true;
        return;
      }
      if (!room->visited)
        _queue.push(room);
      room->visited = true;
    }
  }
  _queue.pop();
  _solved = _queue.empty();
}

void MazeSolver::depthFirstSearch() {
  Room *top = _stack.top();
  top->visited = true;
  _stack.pop();
  if (top->end) {
    top = nullptr;
    _solved = true;
    return;
  }
  for (auto room : top->adjacentRooms) {
    if (room->traversable && !room->visited) {
      _stack.push(room);
    }
  }
  top = nullptr;
  _solved = _stack.empty();
}

void MazeSolver::markUncheckedRooms() {
  Room *room;
  if (_method == "BFS") {
    for (int i = 0; i < _queue.size(); i++) {
      room = _queue.front();
      if (!room->visited)
        room->rect.setFillColor(sf::Color::Blue);
      _queue.pop();
    }
  } else if (_method == "DFS") {
    int leftOver = _stack.size();
    for (int i = 0; i < leftOver; i++) {
      room = _stack.top();
      room->rect.setFillColor(sf::Color::Blue);
      _stack.pop();
    }
  }
  room = nullptr;
}

bool MazeSolver::isSolved() const { return _solved; }