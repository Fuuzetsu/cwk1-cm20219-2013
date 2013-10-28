#include <QtGui>
#include <QtOpenGL>

#include "circle.h"
#include "glwidget.h"
#include "square.h"
#include "polygon.h"

#include <iostream>
#include <stdlib.h>

const double GLWidget::ZMin = -10.0;
const double GLWidget::ZMax = 10.0;

GLWidget::GLWidget(QWidget *parent) :
  QGLWidget(parent),
  mClickLocationX(0),
  mClickLocationY(0),
  mShapeColour(255, 0, 0),
  mHighlightColour(0, 0, 0) {}

void GLWidget::initializeGL() {
  //Set the background colour to white and default depth
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClearDepth(ZMax);

  //Enable features we want to use from OpenGL
  glShadeModel( GL_FLAT );

  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  glPointSize(5);
}

void GLWidget::paintGL() {
  //Clear target buffer and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  //First move the selected shape to last in the list
  //(The posh solution would be to allow the user to change the
  //order)
  if (!mSelectedShape.isNull()) {
    mShapes.remove(mSelectedShape);
    mShapes.push_back(mSelectedShape);
  }

  //Draw every shape
  //(This is what a foreach loop looks like in C++)

  int x = 0;
  for (std::list<shape_ptr>::iterator it = mShapes.begin();
       it != mShapes.end();
       it++) {


    shape_ptr currentShape(*it);
    bool shapeSelected = (currentShape == mSelectedShape);

    currentShape->draw(shapeSelected);
    ++x;
  }

  std::cout << "Drawn " << x << " shapes." << std::endl;

}

void GLWidget::resizeGL(int width, int height) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //Set up the projection matrix as an orthographic projection so that
  //the range 0 <= x <= width and 0 <= y <= height  mapped into NDC
  //(normalised device co-ordinates) i.e. -1 <= x <= 1 etc
  //Also allow -10 < z < 10, to allow 3D rotation
  glOrtho(0.0, width, 0.0, height, ZMin, ZMax);

  //Set thew viewport to the whole widge
  glViewport(0, 0, width, height);

  //Switch back to the model view matrix so that paintGL works correctly
  glMatrixMode(GL_MODELVIEW);
}

void GLWidget::mousePressEvent(QMouseEvent *event) {

  Qt::MouseButton button = event->button();

  if (button==Qt::LeftButton) {
    mClickLocationX = event->x();
    mClickLocationY = event->y();

    //See if the user clicked on a shape
    //(Shapes "on top" are last in the list so we iterate in reverse)
    for (std::list<shape_ptr>::reverse_iterator it = mShapes.rbegin();
         it != mShapes.rend();
         ++it) {
      shape_ptr currentShape(*it);

      //Check if a shape has been clicked on
      //(note that "y" is different between QT and openGL)
      if (currentShape->inside(mClickLocationX, height()-mClickLocationY)) {
        mSelectedShape = currentShape;
        updateGL();
        return;
      }
    }

    //Nothing has been clicked on so deselect (set to null)
    mSelectedShape.clear();
    updateGL();
  }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event) {
  //Tell C++ to shut up about event not being used
  (void)(event);

  updateGL();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event) {

  int mouseX = event->x();
  int mouseY = event->y();

  /* Update the label with mouse position adjusted to widget co-ordinates */
  emit mouseMoved(mouseX, abs(mouseY - height()));

  //Return if no shape selected
  if (mSelectedShape.isNull()) {
    return;
  }

  //Because multiple buttons might be selected we need to handle all buttons
  Qt::MouseButtons buttons = event->buttons();

  if (buttons & Qt::LeftButton) {
    //The user is dragging the left mouse button

    //Move the shape (note that "y" is different between
    //QT and openGL)
    mSelectedShape->translateBy(mouseX - mClickLocationX,
                                mClickLocationY - mouseY);

    //Update mouse click location
    mClickLocationX = mouseX;
    mClickLocationY = mouseY;

    updateGL();
  }
}

void GLWidget::clear() {
  mShapes.clear();

  updateGL();
}

void GLWidget::newSquare() {
  const int defaultSquareSize = 100;

  //Create a new square and make it a QSharedPointer
  shape_ptr newSquare(new square(width()/2, height()/2,
                                 mShapeColour, mHighlightColour, defaultSquareSize));

  //Add it to the list of shapes
  mShapes.push_back(newSquare);

  updateGL();
}


void GLWidget::newCircle() {
  const int defaultRadius = 100;

  //Create a new circle and make it a QSharedPointer
  shape_ptr newCircle(new circle(width()/2, height()/2,
                                 mShapeColour, mHighlightColour, defaultRadius));

  //Add it to the list of shapes
  mShapes.push_back(newCircle);

  updateGL();
}



void GLWidget::newPolygon(QPolygon p) {

  shape_ptr defaultPolygon(new polygon(mShapeColour, mHighlightColour, p));

  mShapes.push_back(defaultPolygon);

  updateGL();
}

void GLWidget::clearShapes() {
  std::cout << "clearing canvas" << std::endl;
  mSelectedShape.clear();
  mShapes.clear();
  updateGL();
}
