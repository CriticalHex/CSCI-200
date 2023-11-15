#include "GuessTheNumberRoom.h"

#include <cstdlib>
#include <iostream>
using namespace std;

GuessTheNumberRoom::GuessTheNumberRoom() {
  cout << "GuessTheNumberRoom() called" << endl;
  mRoomName = "Guess the Number Room";
  _secretNumber = rand() % 20 + 1;
}

GuessTheNumberRoom::~GuessTheNumberRoom() {
  cout << "~GuessTheNumberRoom() called" << endl;
}

bool GuessTheNumberRoom::escapeTheRoom() {
  cout << "Guess the number between 1 and 20! You have 5 attempts." << endl;
  int guess;
  for (int i = 1; i <= 5; i++) {
    cout << "Attempt " << i << ": ";
    cin >> guess;
    if (guess == _secretNumber) {
      return true;
    }
  }
  return false;
}