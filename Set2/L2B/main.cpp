/* CSCI 200: Lab 2B: Pointers: Addresses & Values
 *
 * Author: Kyle Kubaska
 *
 * A program that demonstrates an understanding of pointers
 */

// The include section adds extra definitions from the C++ standard library.
#include <cmath>
#include <iostream> // For cin, cout, etc.

using namespace std;

int main() {
    // Declare iNum and iNum2 with initial values 4 and 5
    // Declare pointers pINum1 and pINum2 both with
    // initial value nullptr.
    int iNum = 4, iNum2 = 5, *pINum1 = nullptr, *pINum2 = nullptr;
    // Assign the address of iNum to pINum1.
    pINum1 = &iNum;
    // Assign the address of iNum2 to pINum2.
    pINum2 = &iNum2;
    // Output the address of iNum two ways.
    cout << "The address of iNum is " << &iNum << " & " << pINum1 << endl;
    // Output the address of iNum2 two ways.
    cout << "The address of iNum2 is " << &iNum2 << " & " << pINum2 << endl;
    // Use pINum1 to display the value of iNum.
    cout << "The value of iNum is " << *pINum1 << endl;
    // Use pINum2 to display the value of iNum2.
    cout << "The value of iNum2 is " << *pINum2 << endl;
    // Directly change the value of iNum to 6.
    iNum = 6;
    // Use iNum to output the value of iNum.
    // Use pINum1 to output the value of iNum.
    cout << "The value of iNum is " << iNum << " & " << *pINum1 << endl;
    // Use pINum1 to change the value it is pointing at to 7.
    *pINum1 = 7;
    // Use iNum to output the value of iNum.
    cout << "The value of iNum is " << iNum << endl;
    // Assign pINum2 to have the same value as pINum1.
    pINum2 = pINum1;
    // Output the value of pINum2.
    cout << "The value of pINum2 is " << pINum2 << endl;
    // Output the value pointed to by pINum2.
    cout << "The value pINum2 points to is " << *pINum2 << endl;
    // Using pINum2, change the value it is pointing at to 8.
    *pINum2 = 8;
    // Output the value of iNum using pINum1, pINum2, and iNum
    cout << "The value of iNum via pINum1 is " << *pINum1 << ", via pINum2 is "
         << *pINum2 << ", and via iNum is " << iNum << endl;
    // Output the value of iNum2.
    cout << "The value of iNum2 is " << iNum2 << endl;
    // Declare a pointer to a double named pDNum with initial value nullptr.
    double *pDNum = nullptr;
    // Try to assign the address of iNum to pDNum.
    // pDNum = &iNum; error: cannot convert 'int*' to 'double*' in assignment
    // Try to assign the value of pINum1 to pDNum.
    // pDNum = pINum1; error: cannot convert 'int*' to 'double*' in assignment
    // Declare a double named dNum with initial value 14.25.
    double dNum = 14.25;
    // Assign the address of dNum to pDNum.
    pDNum = &dNum;
    // Output the address and then the value of dNum using pDNum for both.
    cout << "The address of dNum is " << pDNum << " and the value is " << *pDNum
         << endl;
    // Assign the value pINum1 is pointing at to the value pDNum is pointing at.
    *pINum1 = *pDNum; // downcasts the double to int, value: 14
    // Output the value of dNum two times, first using dNum then using pDNum.
    cout << "The value of dNum is " << dNum << " & " << *pDNum << endl;

    return 0;
}
