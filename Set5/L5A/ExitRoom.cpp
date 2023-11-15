#include "ExitRoom.h"

#include <iostream>
using namespace std;

ExitRoom::ExitRoom() {
  cout << "ExitRoom() called" << endl;
  mRoomName = "Exit";
}

ExitRoom::~ExitRoom() { cout << "~ExitRoom() called" << endl; }

bool ExitRoom::escapeTheRoom() { return true; }
