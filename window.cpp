#include <iostream>
#include <QtGui>
#include <QtOpenGL>
#include "version.h"
#include "window.h"

//------------------------------------------------------------------------------------
// Creates and initializes the main window for application
//------------------------------------------------------------------------------------
Window::Window(QWidget *parent) :
  QDialog(parent) {
  ui.setupUi(this);
}

void Window::updateMouseLabel(int x, int y) {
  ui.mousePositionLabel->setText(QString("Mouse: (%1, %2)").arg(x).arg(y));
}

void Window::aboutBut() {
  QString title = "QtOpenGl-2 ";
  QString mess = "QtOpenGl-basic by Brian Wyvill Release Version: " + QString::number(MY_VERSION);
  QMessageBox::information( this, title, mess, QMessageBox::Ok );
}
