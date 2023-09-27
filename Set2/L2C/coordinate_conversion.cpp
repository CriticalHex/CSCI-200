#include "coordinate_conversion.h"
#include <cmath>

double PI = 3.14159265358979;

/**
 * @brief Converts polar (r, θ) to cartesian (x, y).
 *
 * @param RADIUS double passed by constant value corresponding to the radius
 * @param THETA double passed by constant value corresponding to the angle
 * @param x double passed by pointer corresponding to the xCoordinate
 * @param y double passed by pointer corresponding to the yCoordinate
 */
void polar_to_cartesian(const double RADIUS, const double THETA, double *x,
                        double *y) {
  *x = RADIUS * cos(radians(THETA));
  *y = RADIUS * sin(radians(THETA));
}

/**
 * @brief Converts cartesian (x, y) to polar (r, θ).
 *
 * @param X double passed by constant value corresponding to the xCoordinate
 * @param Y double passed by constant value corresponding to the yCoordinate
 * @param radius double passed by pointer corresponding to the radius
 * @param theta double passed by pointer corresponding to the angle
 */
void cartesian_to_polar(const double X, const double Y, double *radius,
                        double *theta) {
  *radius = sqrt(pow(X, 2) + pow(Y, 2));
  *theta = degrees(atan(Y / X)) + ((X > 0) ? 0 : 180);
  // adds pi radians if the point is on the left
  // half of the unit circle.
}

/**
 * @brief converts radians to degrees
 *
 * @param RADIAN double corresponding to the value in radians
 * @return double corresponsing to the value in degrees
 */
double degrees(const double RADIAN) { return RADIAN * 180 / PI; }

/**
 * @brief converts degrees to radians
 *
 * @param double corresponding to the value in degrees
 * @return double corresponsing to the value in radians
 */
double radians(const double DEGREE) { return DEGREE * PI / 180; }