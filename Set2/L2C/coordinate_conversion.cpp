#include "coordinate_conversion.h"

void polar_to_cartesian(const double radius, const double theta, double *x,
                        double *y) {
    *x = radius * cos(theta);
    *y = radius * sin(theta);
}
void cartesian_to_polar(const double x, const double y, double *radius,
                        double *theta) {
    *radius = sqrt(pow(x, 2) + pow(y, 2));
    *theta = degrees(atan(y / x)) +
             ((x > 0) ? 0 : 180); // adds pi radians if the point is on the left
                                  // half of the unit circle.
}

double degrees(const double radian) {
    return radian * 180 / 3.14159265358979;
} // degrees to radians