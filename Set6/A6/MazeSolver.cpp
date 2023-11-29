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
  maze.getStartRoom()->visit();
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
  if (_solved) {
    markUncheckedRooms();
    highlightPath();
  }
}

void MazeSolver::breadthFirstSearch() {
  for (auto room : _queue.front()->adjacentRooms) {
    if (room->isTraversable()) {
      if (room->isEnd()) {
        room->parent = _queue.front();
        room->visit();
        _solved = true;
        return;
      }
      if (!room->isVisited()) {
        _queue.push(room);
        room->visit();
        room->parent = _queue.front();
      }
    }
  }
  _queue.pop();
  _solved = _queue.empty();
}

void MazeSolver::depthFirstSearch() {
  Room *top = _stack.top();
  top->visit();
  _stack.pop();
  if (top->isEnd()) {
    top = nullptr;
    _solved = true;
    return;
  }
  for (auto room : top->adjacentRooms) {
    if (room->isTraversable() && !room->isVisited()) {
      _stack.push(room);
      room->parent = top;
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
      if (!room->isVisited())
        room->rect.setFillColor(sf::Color::Blue);
      _queue.pop();
    }
  } else if (_method == "DFS") {
    int leftOver = _stack.size();
    for (int i = 0; i < leftOver; i++) {
      room = _stack.top();
      if (!room->isVisited())
        room->rect.setFillColor(sf::Color::Blue);
      _stack.pop();
    }
  }
  room = nullptr;
}

bool MazeSolver::isSolved() const { return _solved; }

void MazeSolver::highlightPath() {
  Room *root = maze.getEndRoom()->parent;
  while (root != nullptr) {
    if (root->isVisited() && !root->isStart())
      root->rect.setFillColor(sf::Color::Yellow);
    root = root->parent;
  }
}