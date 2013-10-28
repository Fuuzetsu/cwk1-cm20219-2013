#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class square : public shape {
public:
  square(int XCentre, int YCentre, const QColor &colour, const QColor &selectedColour, unsigned int sideLength);

private:
  //Implemented functions for drawing and checking if inside the shape, specified by the base class, shape
  virtual void drawShape();
  virtual bool insideZeroCentredShape(int x, int y);

  unsigned int mSideLength;
};

#endif
