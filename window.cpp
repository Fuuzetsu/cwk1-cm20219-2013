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

void Window::disableDeleteButton() {
  ui.deleteMatrixButton->setEnabled(false);
}

void Window::enableDeleteButton() {
  ui.deleteMatrixButton->setEnabled(true);
}

void Window::disableAddButton() {
  ui.addMatrixButton->setEnabled(false);
}

void Window::enableAddButton() {
  ui.addMatrixButton->setEnabled(true);
}

void Window::populateMatrixList(shape *s) {
  /* Clear the list before populating it again */
  ui.matrixList->clear();

  QStack<QMatrix4x4> st = s->getMatrixStack();

  QStack<QMatrix4x4>::const_iterator i;

  for (i = st.constBegin(); i != st.constEnd(); ++i) {
    QMatrix4x4 m = (*i);
    QString str;
    for (int r = 0; r < 4; ++r) {
      QVector4D v = m.row(r);
      str = str + QString("%1 %2 %3 %4; ").arg(v.x()).arg(v.y())
        .arg(v.z()).arg(v.w());
    }
    ui.matrixList->addItem(str);
  }
  enableAddButton();
  if (st.size() > 0) {
    enableDeleteButton();
  } else {
    disableDeleteButton();
  }
}

void Window::clearMatrixList() {
  ui.matrixList->clear();
  /* Disable the buttons as well considering nothing is now selected.
   * Perhaps a better name for this method is in order.
   */
  disableAddButton();
  disableDeleteButton();
}
