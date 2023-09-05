/* CSCI 200: Lab 1B: Random Classification
 *
 * Author: Kyle Kubaska
 *
 */

#include <ctime>
#include <iostream>
#include <random>

using namespace std;

float random(const float min, const float max) {
  return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}

int main() {
  srand(time(NULL));
  float min, max;
  char userIn;
  do {
    cout << "Enter the minimum value: ";
    cin >> min;
    cout << "Enter the maximum value: ";
    cin >> max;
    float randomNumber = random(min, max);
    cout << "A random number is: " << randomNumber << endl;
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
    cout << "Do you want another random value? (Y/N) ";
    cin >> userIn;
  } while (userIn == 'Y');
  cout << "Have a nice day!";
  return 0;
}