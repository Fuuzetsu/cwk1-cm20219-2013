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
  //Constructor
  Window(QWidget *parent = 0);

 private:
  //GLWidget instance---by storing an instance, the widget is automatically created
  //and cleared up when the Window class is instantiated (i.e. no need for new/delete)
  GLWidget mGLWidget;
  Ui::mainForm ui;

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

 signals:
   void spawnPolygon(QPolygon p);

};


#endif
