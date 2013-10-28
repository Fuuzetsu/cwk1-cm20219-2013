#include <iostream>
#include <QtGui>
#include <QtOpenGL>
#include "version.h"
#include "window.h"
#include <QRegExp>
#include <QStringList>

//------------------------------------------------------------------------------------
// Creates and initializes the main window for application
//------------------------------------------------------------------------------------
Window::Window(QWidget *parent) :
  QDialog(parent) {
  ui.setupUi(this);
}

void Window::updateMouseLabel(int x, int y) {
  if (x < 0 || y < 0) {
    ui.mousePositionLabel->setText(QString("Mouse out of canvas"));
  } else {
    ui.mousePositionLabel->setText(QString("Mouse: (%1, %2)").arg(x).arg(y));
  }
}

void Window::updateShapeNumber(int n) {
  ui.shapeNumberLabel->setText(QString("Have %1 shapes.").arg(n));
}

void Window::aboutBut() {
  QString title = "QtOpenGl-2 ";
  QString mess = "QtOpenGl-basic by Brian Wyvill Release Version: " + QString::number(MY_VERSION);
  QMessageBox::information( this, title, mess, QMessageBox::Ok );
}

void Window::createPolygon() {
  QString s = ui.polygonEdit->displayText();
  QRegExp r("(\\d+\\s\\d+);+");
  QStringList list;
  int pos = 0;

  while ((pos = r.indexIn(s, pos)) != -1) {
    list << r.cap(1);
    pos += r.matchedLength();
  }

  QPolygon p;

  for (int i = 0; i < list.size(); ++i) {
    QStringList l = list.at(i).split(" ");
    p << QPoint(l.at(0).toInt(), l.at(1).toInt());
  }

  emit spawnPolygon(p);
}
