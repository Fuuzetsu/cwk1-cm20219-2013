#include "square.h"

square::square(int XCentre, int YCentre, const QColor &colour, const QColor &selectedColour, unsigned int sideLength) :
  shape(XCentre, YCentre, colour, selectedColour),
  mSideLength(sideLength) {
}

void square::drawShape() {
  float halfSide = mSideLength/2;

  glVertex2i(-halfSide, -halfSide);
  glVertex2i(halfSide,  -halfSide);
  glVertex2i(halfSide,  halfSide);
  glVertex2i(-halfSide, halfSide);
}

bool square::insideZeroCentredShape(int x, int y) {
  float halfSide = mSideLength/2;

  if (x <= halfSide &&
      x >= -halfSide &&
      y <= halfSide &&
      y >= -halfSide) {
    return true;
  } else {
    return false;
  }
}
