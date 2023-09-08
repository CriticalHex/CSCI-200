/* CSCI 200: Lab 1B: Random Classification
 *
 * Author: Kyle Kubaska
 *
 * A program that generates a random number between a given range, and evaluates
 * which quarter of that range it fall in
 *
 */

#include <ctime>    // to seed the random number generator
#include <iostream> // for cin, cout
#include <random>   //for random numbers

using namespace std;

float random(const float min, const float max) {
  // generate random number in range min-max
  return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}

int main() {
  // seed random number with current time (a value that won't
  // happen again)
  srand(time(NULL));
  // declare variables
  float min, max;
  char userIn;
  do { // execute at least once
    // prompt user and assign variables
    cout << "Enter the minimum value: ";
    cin >> min;
    cout << "Enter the maximum value: ";
    cin >> max;
    // generate random number with custom function
    float randomNumber = random(min, max);
    cout << "A random number is: " << randomNumber << endl;
    // calculate and print the quartile of the random number
    float percentile = randomNumber / (max - min);
    if (percentile >= .75) {
      cout << "This is in the fourth quartile." << endl;
    } else if (percentile >= .5) {
      cout << "This is in the third quartile." << endl;
    } else if (percentile >= .25) {
      cout << "This is in the second quartile." << endl;
    } else {
      cout << "This is in the first quartile." << endl;
    }
    // go again!
    cout << "Do you want another random value? (Y/N) ";
    cin >> userIn;
  } while (userIn == 'Y');
  cout << "Have a nice day!";
  return 0; // signal a succesful run
}