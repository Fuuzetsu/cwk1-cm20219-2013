//-------------------------------------------------------------------------------------------
//  University of Bath Computer Science Department
//  FrameWork for OpenGL application under QT
//  Course title: Introduction Computer Graphics
//-------------------------------------------------------------------------------------------
#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QColorDialog>
#include "ui_MainWindow.h"
#include "glwidget.h"

class GLWidget;

class Window : public QDialog {
  Q_OBJECT;

 public:
  Window(QWidget *parent = 0);

 private:
  GLWidget mGLWidget;
  Ui::mainForm ui;
  shape *currentShape;

 private slots:
   void aboutBut();
   void createPolygon();

 public slots:
   void updateMouseLabel(int x, int y);
   void updateShapeNumber(int n);
   void disableDeleteButton();
   void enableDeleteButton();
   void disableAddButton();
   void enableAddButton();
   void populateMatrixList(shape *s);
   void clearMatrixList();
   void addMatrixToShape();
   void removeMatrixFromShape();
   void makeCircle();

 signals:
   void spawnPolygon(QPolygon p);
   void spawnCircle(int radius);
   void matrixStackUpdated();

};


#endif
