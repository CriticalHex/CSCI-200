/* CSCI 200: Lab 2C: Coordinate Conversion By Pointer
 *
 * Author: Kyle Kubaska
 *
 * A program that converts coordinates via pointers
 */

// The include section adds extra definitions from the C++ standard library.
#include "coordinate_conversion.h"
#include <cmath>
#include <iostream> // For cin, cout, etc.

using namespace std;

int main() {
    string userIn;
    double x, y, r, theta;
    cout << "Enter either 'p' or 'c': ";
    cin >> userIn;
    if (userIn == "p") {
        cout << "Enter an x and a y value seperated by a space: ";
        cin >> x >> y;
        cartesian_to_polar(x, y, &r, &theta);
        cout << "The calculated radius is " << r << endl;
        cout << "The calculated theta is " << theta << endl;
    } else if (userIn == "c") {
        cout << "Enter a radius and a theta value seperated by a space: ";
        cin >> r >> theta;
        polar_to_cartesian(r, theta, &x, &y);
        cout << "The calculated x is " << x << endl;
        cout << "The calculated y is " << y << endl;
    }
}