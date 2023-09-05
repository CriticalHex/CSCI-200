/* CSCI 200: Lab 1A: Math Equation Solver
 *
 * Author: Kyle Kubaska
 *
 * More complete description here...
 */

// The include section adds extra definitions from the C++ standard library.
#include <cmath>
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our
// programs.
using namespace std;

// Define any constants below this comment.
float ohmsLaw(const float voltage, const float resistance) {
  return voltage / resistance; // current
}

float distance(const float x, const float y) {
  return sqrt(pow(x, 2.0f) + pow(x, 2.0f));
}

string promptFor(const string prompt) {
  string userIn;
  cout << prompt;
  cin >> userIn;
  return userIn;
}

// Must have a function named "main", which is the starting point of a C++
// program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/
  float x, y, voltage, resistance;
  voltage = stof(promptFor("Enter the voltage: "));
  resistance = stof(promptFor("Enter the resistance: "));
  cout << "The current is: " << ohmsLaw(voltage, resistance) << endl;
  x = stof(promptFor("Enter the x: "));
  y = stof(promptFor("Enter the y: "));
  cout << "The distance is: " << distance(x, y) << endl;

  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}