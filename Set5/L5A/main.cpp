#include "ExitRoom.h"
#include "GuessTheNumberRoom.h"

#include <cstdlib>
#include <iostream>
using namespace std;

ARoom *go_to_next_room() {
  int randRoomChoice = rand() % 10; // a 10% chance to get directly out
  switch (randRoomChoice) {
  case 7:
    return new ExitRoom();
  default:
    return new GuessTheNumberRoom();
  }
}

int main() {
  srand(time(0));
  rand();

  ARoom *currentRoom;

  do {
    // delete currentRoom;
    // currentRoom = nullptr;
    currentRoom = go_to_next_room();
    cout << "Welcome to the " << currentRoom->getRoomName() << endl;
  } while (!currentRoom->escapeTheRoom());

  cout << "You made it out!" << endl;

  return 0;
}