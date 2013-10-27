#include "shape.h"

shape::shape(int XCentre, int YCentre, const QColor& colour, const QColor& selectedColour):
  mXCentre(XCentre),
  mYCentre(YCentre),
  mNormalColour(colour),
  mSelectedColour(selectedColour)
{
}

shape::~shape()
{}

void shape::draw(bool selected)
{
  //Ensure we're in the correct mode for drawing
  glMatrixMode(GL_MODELVIEW);

  //In order to translate only this shape, we need to push and pop the current matrix
  glPushMatrix();
     
  //Translate the shape so that its centre is in the right location
  glTranslated(mXCentre, mYCentre, 0.0);

  //This might be a good place to add other transformations
  //(Here's an example, the identity matrix)
  GLdouble matrix[4][4];
  matrix[0][0] = 1;
  matrix[0][1] = 0;
  matrix[0][2] = 0;
  matrix[0][3] = 0;
  matrix[1][0] = 0;
  matrix[1][1] = 1;
  matrix[1][2] = 0;
  matrix[1][3] = 0;
  matrix[2][0] = 0;
  matrix[2][1] = 0;
  matrix[2][2] = 1;
  matrix[2][3] = 0;
  matrix[3][0] = 0;
  matrix[3][1] = 0;
  matrix[3][2] = 0;
  matrix[3][3] = 1;
  glMultMatrixd(&matrix[0][0]);

  //Set the colour
  glColor3f(mNormalColour.redF(), mNormalColour.greenF(), mNormalColour.blueF());
  
  //Draw the actual shape
  glBegin(GL_POLYGON);
  drawShape();
  glEnd();

  //If it's selected, draw a highlight
  if(selected)
  {
    glColor3f(mSelectedColour.redF(), mSelectedColour.greenF(), mSelectedColour.blueF());

    const float lineWidth = 3.0;
    glLineWidth(lineWidth);

    glBegin(GL_LINE_LOOP);
    drawShape();
    glEnd();
  }

  //Restore the original matrix
  glPopMatrix();
}

void shape::setCentre(int X, int Y)
{
  mXCentre = X;
  mYCentre = Y;
}

void shape::translateBy(int X, int Y)
{
    mXCentre += X;
    mYCentre += Y;
}


bool shape::inside(int x, int y)
{
  //Translate the co-ordinates
  bool insideShape = insideZeroCentredShape(x-mXCentre, mYCentre-y);

  return insideShape;
}


