#include <QtGui>
#include <QtOpenGL>

#include "glwidget.h"
#include "polygon.h"

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
    bool shapeSel = (currentShape == mSelectedShape);
    currentShape->draw(shapeSel);
    ++x;
  }

  emit shapesDrawn(x);

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

        emit shapeSelected(mSelectedShape.data());

        updateGL();
        return;
      }
    }

    //Nothing has been clicked on so deselect (set to null)
    mSelectedShape.clear();
    emit shapeDeselected();
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
    mSelectedShape->translateBy(mouseX - mClickLocationX ,
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
  /* Square is just a 4-sided polygon with 2 pairs of parallel sides. */
  const int squareSize = 100;
  const int hs = squareSize / 2;

  const int w = width() / 4 + hs / 2;
  const int h = height() / 4 + hs / 2;

  QVector<QPoint> v;
  v << QPoint(-hs + w, -hs + h);
  v << QPoint(hs + w ,  -hs + h);
  v << QPoint(hs + w ,  hs + h);
  v << QPoint(-hs + w, hs + h);

  shape_ptr square(new polygon(mShapeColour, mHighlightColour, v));

  mShapes.push_back(square);
  updateGL();
}


void GLWidget::newCircle(const int radius) {
  /* Considering this was represented as a polygon, we re-use our
   * polygon class rather than coming up with weird ways
   * to check point membership in a circle-but-not-actually-a-circle.
   */

  QVector<QPoint> v;

  /* 1000 points around is good enough. */
  const int coords = 1000;

  /* Got to make sure we render nicely in the middle. */
  const int r = radius / 2;
  const int w = width() / 4;
  const int h = height() / 4;

  for (int i = 0; i < coords; ++i) {

    const int x = radius*qCos(2.0*i*M_PI/(double)coords);
    const int y = radius*qSin(2.0*i*M_PI/(double)coords);

    v << QPoint(x - r + w, y + h);
  }

  shape_ptr circle(new polygon(mShapeColour, mHighlightColour, v));

  mShapes.push_back(circle);
  updateGL();
}


void GLWidget::newPolygon(QPolygon p) {

  shape_ptr defaultPolygon(new polygon(mShapeColour, mHighlightColour, p));

  mShapes.push_back(defaultPolygon);

  updateGL();
}

void GLWidget::clearShapes() {
  mSelectedShape.clear();
  mShapes.clear();
  updateGL();
}

void GLWidget::redrawScene() {
  updateGL();
}
