#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class circle : public shape {
public:
  circle (int XCentre, int YCentre, const QColor &colour,
          const QColor &selectedColour, unsigned int radius);

private:
  //Implemented functions for drawing and checking if inside the shape, specified by the base class, shape
  virtual void drawShape();
  virtual bool insideZeroCentredShape(int x, int y);

  unsigned int mRadius;
};

#endif // CIRCLE_H
