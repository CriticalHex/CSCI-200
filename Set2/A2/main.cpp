#include "vectorMath.h"
#include <iostream>

using namespace std;

int main() {
  float pointX, pointY, vectorX, vectorY, rotatedX, rotatedY, angle,
      normalizedX, normalizedY, rotationAngle, centerX, centerY;
  int choice;

  while (true) {
    cout << "Menu:" << endl;
    cout << "        1) Enter point (x, y) coordinate" << endl;
    cout << "        2) Rotate point by angle" << endl;
    cout << "        3) Rotate point by vector" << endl;
    cout << "        4) Rotate point by vector around point" << endl;
    cout << "        0) Quit" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
    case 0: {
      cout << "Goodbye!" << endl;
      return 0;
    }
    case 1: {
      point_input(&pointX, &pointY);
      break;
    }
    case 2: {
      angle_input(&angle);
      angle_to_vector(angle, &vectorX, &vectorY);
      rotate_point_by_vector(pointX, pointY, vectorX, vectorY, &rotatedX,
                             &rotatedY);
      cout << "The point (" << pointX << ", " << pointY << ") rotated by "
           << angle << " degrees is now at (" << rotatedX << ", " << rotatedY
           << ")" << endl;
      pointX = rotatedX;
      pointY = rotatedY;
      break;
    }
    case 3: {
      vector_input(&vectorX, &vectorY);
      vector_normalize(vectorX, vectorY, &normalizedX, &normalizedY);
      rotationAngle = vector_to_angle(normalizedX, normalizedY);
      rotate_point_by_vector(pointX, pointY, normalizedX, normalizedY,
                             &rotatedX, &rotatedY);
      cout << "The point (" << pointX << ", " << pointY
           << ") rotated by the vector <" << vectorX << ", " << vectorY << "> ("
           << rotationAngle << " degrees) is now at (" << rotatedX << ", "
           << rotatedY << ")" << endl;
      pointX = rotatedX;
      pointY = rotatedY;
      break;
    }
    case 4:
      point_input(&centerX, &centerY);  // get point to rotate around
      vector_input(&vectorX, &vectorY); // get vector to rotate by
      vector_normalize(vectorX, vectorY, &normalizedX, &normalizedY);
      rotationAngle = vector_to_angle(normalizedX, normalizedY);
      rotate_point_by_vector(pointX - centerX, pointY - centerY, normalizedX,
                             normalizedY, &rotatedX, &rotatedY);
      cout << "The point (" << pointX << ", " << pointY
           << ") rotated by the vector <" << vectorX << ", " << vectorY << "> ("
           << rotationAngle << " degrees) around the point (" << centerX << ", "
           << centerY << ") is now at (" << rotatedX + centerX << ", "
           << rotatedY + centerY << ")" << endl;
      pointX = rotatedX;
      pointY = rotatedY;
      break;
    default:
      cout << "Invalid selection, enter a valid option" << endl;
      break;
    }
  }

  return 0;
}
