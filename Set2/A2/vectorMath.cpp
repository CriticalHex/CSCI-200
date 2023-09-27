#include "vectorMath.h"
#include <cmath>
#include <iostream>

using namespace std;

/**
 * @brief Prompts the user to enter an angle and updates the corresponding
 * parameter. Be sure to specify to the user what units they are working with.
 *
 * @param angle A float pointer corresponding to the angle
 */
void angle_input(float *angle) {
  cout << "Enter angle in degrees: ";
  cin >> *angle;
}

/**
 * @brief Converts an angle with the positive X-axis to the resultant vector on
 * the unit circle
 *
 * @param angle A float corresponding to the angle from the positive X-axis
 * @param vectorX A float pointer corresponding to the resultant vector's x
 * coordinate
 * @param vectorY A float pointer corresponding to the resultant vector's y
 * coordinate
 */
void angle_to_vector(float angle, float *vectorX, float *vectorY) {
  float radians = angle * (M_PI / 180.0); // Convert degrees to radians
  *vectorX = cos(radians);
  *vectorY = sin(radians);
}

/**
 * @brief Prompts the user to enter the (x, y) coordinate and updates the
 * corresponding parameters.
 *
 * @param x A float pointer corresponding to the point's x coordinate
 * @param y A float pointer corresponding to the point's y coordinate
 */
void point_input(float *x, float *y) {
  cout << "Enter point x coordinate: ";
  cin >> *x;
  cout << "Enter point y coordinate: ";
  cin >> *y;
}

/**
 * @brief Prompts the user to enter the <x, y> coordinate and updates the
 * corresponding parameters.
 *
 * @param vectorX A float pointer corresponding to the vector's x coordinate
 * @param vectorY A float pointer corresponding to the vector's y coordinate
 */
void vector_input(float *vectorX, float *vectorY) {
  cout << "Enter vector x coordinate: ";
  cin >> *vectorX;
  cout << "Enter vector y coordinate: ";
  cin >> *vectorY;
}

/**
 * @brief Normalizes the input vector setting the corresponding pointer
 * parameters to the output normalized vector
 *
 * @param vectorX A float corresponding to the input vector's x coordinate
 * @param vectorY A float corresponding to the input vector's y coordinate
 * @param normalizedX A float pointer corresponding to the output normalized
 * vector's x coordinate
 * @param normalizedY A float pointer corresponding to the output normalized
 * vector's y coordinate
 */
void vector_normalize(float vectorX, float vectorY, float *normalizedX,
                      float *normalizedY) {
  float magnitude = sqrt(vectorX * vectorX + vectorY * vectorY);
  *normalizedX = vectorX / magnitude;
  *normalizedY = vectorY / magnitude;
}

/**
 * @brief Determines the angle the vector forms with the positive X-axis based
 * on where it intersects the unit circle. Angle is computed by taking the
 * arctan of y over x. Be sure to handle edge cases correctly.
 *
 * @param vectorX A float corresponding to the vector's x coordinate
 * @param vectorY A float corresponding to the vector's y coordinate
 * @return A float corresponding to the angle the vector forms with the positive
 * X-axis
 */
float vector_to_angle(float vectorX, float vectorY) {
  return atan2(vectorY, vectorX) *
         (180.0 / M_PI); // vector to angle and radians to degrees
}

/**
 * @brief Performs the rotation by multiplying complex numbers. Form a complex
 * number using the point (px, py) coordinate: px + pyi. Form a second complex
 * number using the vector <vx, vy> coordinate: vx + vyi. Multiply these two
 * complex numbers to compute the resultant point:
 *
 * @param x A float corresponding to the input point's x coordinate
 * @param y A float corresponding to the input point's y coordinate
 * @param vectorX A float corresponding to the input vector's x coordinate
 * @param vectorY A float corresponding to the input vector's y coordinate
 * @param rotatedX A float pointer corresponding to the output rotated point's x
 * coordinate
 * @param rotatedY A float pointer corresponding to the output rotated point's y
 * coordinate
 */
void rotate_point_by_vector(float x, float y, float vectorX, float vectorY,
                            float *rotatedX, float *rotatedY) {
  // matmul
  *rotatedX = x * vectorX - y * vectorY;
  *rotatedY = x * vectorY + y * vectorX;
}