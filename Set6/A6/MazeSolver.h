#ifndef MAZESOLVE_H
#define MAZESOLVE_H
#include "Maze.h"

class MazeSolver {
private:
  bool _solved;
  std::string _method;

public:
  Maze maze;
  MazeSolver(int, char **);
  ~MazeSolver();
  bool isSolved() const;
  void solve();
  void breadthFirstSearch();
  void depthFirstSearch();
};

#endif