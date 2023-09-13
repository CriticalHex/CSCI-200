/* CSCI 200: Lab 1A: Math Equation Solver
 *
 * Author: Kyle Kubaska
 *
 * A program that demonstrates an understanding of pointers
 */

// The include section adds extra definitions from the C++ standard library.
#include <cmath>
#include <iostream>  // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our
// programs.
using namespace std;

int main() {
    int iNum = 4, iNum2 = 5, *pINum1 = nullptr, *pINum2 = nullptr;
    pINum1 = &iNum;
    pINum2 = &iNum2;
    cout << "The address of iNum is " << &iNum << " & " << pINum1 << endl;
    cout << "The address of iNum2 is " << &iNum2 << " & " << pINum2 << endl;

    return 0;
}
