/* CSCI 200: Lab 1A: Math Equation Solver
 *
 * Author: Kyle Kubaska
 *
 * Two equations are defined, and the user is prompted to
 * enter the input values, the output is then calculated
 * and written to the console.
 */

// The include section adds extra definitions from the C++ standard library.
#include <cmath>    // for square root
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our
// programs.
using namespace std;

float ohmsLaw(const float voltage, const float resistance) {
  return voltage / resistance; // current
}

float distance(const float x, const float y) {
  return sqrt(pow(x, 2.0f) + pow(x, 2.0f)); // sqrt(x^2+y^2)
}

string promptFor(const string prompt) {
  string userIn;
  cout << prompt;
  cin >> userIn; // prompt the user, written so as to not use these 4 lines for
  return userIn; // one task over and over
}

// Must have a function named "main", which is the starting point of a C++
// program.
int main() {
  float x, y, voltage, resistance; //declare variables
  voltage = stof(promptFor("Enter the voltage: ")); //stof converts a string to a float
  resistance = stof(promptFor("Enter the resistance: "));
  cout << "The current is: " << ohmsLaw(voltage, resistance) << endl;
  x = stof(promptFor("Enter the x: "));
  y = stof(promptFor("Enter the y: "));
  cout << "The distance is: " << distance(x, y) << endl;

  return 0; // signals the operating system that our program ended OK.
}