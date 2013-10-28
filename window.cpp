#include <iostream>
#include <QtGui>
#include <QtOpenGL>
#include "version.h"
#include "window.h"

//------------------------------------------------------------------------------------
// Creates and initializes the main window for application
//------------------------------------------------------------------------------------
Window::Window(QWidget *parent):QDialog(parent)
{
  //Setup application interface. Creates all the required components and sliders.
  setupUi(this);

  //We need to attach our m_glWidget to glWidgetArea
  //All our drawings will be on glWidgetArea
  //glWidgetArea->setWidget(&mGLWidget);
}



void Window::aboutBut()
{
    QString title="QtOpenGl-2 ";
    QString mess = "QtOpenGl-basic by Brian Wyvill Release Version: " + QString::number(MY_VERSION);
    QMessageBox::information( this, title, mess, QMessageBox::Ok );
}
