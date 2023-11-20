#include "MazeSolver.h"
#include <iostream>

using namespace std;

MazeSolver::MazeSolver(int argc, char **argv) {
  if (argc > 1) {
    maze.create(string(*(argv + 1)));
  } else {
    string filename;
    cout << "Enter a filename: ";
    cin >> filename;
    maze.create(filename);
  }
  maze.addAdjacencies();
  cout << "How would you like to solve the maze? ('BFS'/'DFS'): ";
  cin >> _method;
}

MazeSolver::~MazeSolver() {}

void MazeSolver::solve() {
  if (_method == "BFS")
    breadthFirstSearch();
  else if (_method == "DFS")
    depthFirstSearch();
}

void MazeSolver::breadthFirstSearch() {}

void MazeSolver::depthFirstSearch() {}

bool MazeSolver::isSolved() const { return _solved; }