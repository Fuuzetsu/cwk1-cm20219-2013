#include "polygon.h"

#include <iostream>

polygon::polygon(const QColor &colour, const QColor &selectedColour,
                 const QVector<QPoint> vertices) :
  shape(vertices.at(0).x(), vertices.at(0).y(), colour, selectedColour),
  m_poly(vertices) {
  m_MatrixStack.push(QMatrix4x4(3.0, 0.0, 0.0, 0.0,
                                0.0, 3.0, 0.0, 0.0,
                                0.0, 0.0, 3.0, 0.0,
                                0.0, 0.0, 0.0, 1.0));
  }

void polygon::drawShape() {

  QPolygon::const_iterator i;
  for (i = m_poly.constBegin(); i != m_poly.constEnd(); ++i) {
    QPointF pf(*i);

    QStack<QMatrix4x4>::const_iterator j;
    for (j = m_MatrixStack.constBegin(); j != m_MatrixStack.constEnd(); ++j) {
      pf = (*j) * pf;
    }

    glVertex2f(pf.x(), pf.y());
  }

}

bool polygon::insideZeroCentredShape(int x, int y) {
  /* We create a transformed polygon and check the point on that.
   * While it's not the most efficient way (we could for example store the
   * transformed shape when drawing, keeping track of the stack state), it
   * shouldn't matter in this simple use-case.
   */
  QPolygon p;

  QPolygon::const_iterator i;
  for (i = m_poly.constBegin(); i != m_poly.constEnd(); ++i) {
    QPointF pf(*i);

    QStack<QMatrix4x4>::const_iterator j;
    for (j = m_MatrixStack.constBegin(); j != m_MatrixStack.constEnd(); ++j) {
      pf = (*j) * pf;
    }

    p << pf.toPoint();
  }
  /* We have to flip y for the GL co-ordinates*/
  return p.containsPoint(QPoint(x, -y), Qt::OddEvenFill);
}
