#ifndef SHAPE_H_
#define SHAPE_H_

#include <QtOpenGL>
#include <QStack>
#include <QMatrix4x4>

class shape {
public:
  shape(int XCentre, int YCentre, const QColor &colour, const QColor &selectedColour);

  //Virtual destructor: This is a must in c++ for virtual base classes to make delete
  //work correctly
  virtual ~shape();

  //This is a public method called to draw the shape. This should not be overidden
  //as it will translate the shape to the correct position and call drawShape
  void draw(bool selected);

  void setCentre(int X, int Y);

  void translateBy(int X, int Y);

  //This is a public method called to check if the co-ordinates are inside the shape
  bool inside(int x, int y);

private:
  //This is a pure virtual function (indicated by = 0), which is defined by the
  //derived classes, e.g. square. The drawn shape should be centred on (0, 0)
  virtual void drawShape() = 0;

  //This is defined by the derived classes to check if the point is inside the shape
  //(centred on (0,0), i.e. the centre is taken care of
  virtual bool insideZeroCentredShape(int x, int y) = 0;

  int mXCentre;
  int mYCentre;

  QColor mNormalColour;
  QColor mSelectedColour;

 protected:
  QStack<QMatrix4x4> m_MatrixStack;
};

#endif
