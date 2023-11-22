#ifndef MAZESOLVE_H
#define MAZESOLVE_H
#include "Maze.h"
#include <queue>
#include <stack>

class MazeSolver {
private:
  bool _solved;
  std::string _method;
  std::queue<Room *> _queue;
  std::stack<Room *> _stack;
  std::vector<Room *> _visited;

public:
  Maze maze;
  MazeSolver(int, char **);
  ~MazeSolver();
  bool isSolved() const;
  void solve();
  void breadthFirstSearch();
  void depthFirstSearch();
  void markUncheckedRooms();
};

#endif