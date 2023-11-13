#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle() {}

bool EquilateralTriangle::validate() {
  double l1, l2, l3;
  l1 = getSideLength(0, 1);
  l2 = getSideLength(1, 2);
  l3 = getSideLength(2, 0);
  if (isTriangle(l1, l2, l3) && l1 == l2 && l2 == l3)
    return true;
  return false;
}