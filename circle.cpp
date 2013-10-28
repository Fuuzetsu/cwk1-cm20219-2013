#include <QtCore/qmath.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288419717
#endif

#include "circle.h"

circle::circle(int XCentre, int YCentre, const QColor &colour,
               const QColor &selectedColour, unsigned int radius) :
  shape(XCentre, YCentre, colour, selectedColour),
  mRadius(radius) {
}

void circle::drawShape() {
  const unsigned int numCoords = 1000;

  //Draw 1000 coordinates of the circle
  for (unsigned int i = 0;
       i < numCoords;
       i++) {
    int X = mRadius*qCos(2.0*i*M_PI/(double)numCoords)+0.5;
    int Y = mRadius*qSin(2.0*i*M_PI/(double)numCoords)+0.5;

    glVertex2i(X, Y);
  }

}

bool circle::insideZeroCentredShape(int x, int y) {
  float distFromCentre = qSqrt(x*x+y*y);

  return (distFromCentre <= mRadius);
}
