#include "polygon.h"

#include <iostream>

polygon::polygon(const QColor &colour, const QColor &selectedColour,
                 const QVector<QPoint> vertices) :
  shape(vertices.at(0).x(), vertices.at(0).y(), colour, selectedColour),
  m_poly(vertices) {}

void polygon::drawShape() {
  QPolygon::const_iterator i;
  for (i = m_poly.constBegin(); i != m_poly.constEnd(); ++i) {
    glVertex2i(i->x(), i->y());
    // std::cout << "Vertex: (" << i->x() << ", " << i->y() << ")" << std::endl;
  }
}

bool polygon::insideZeroCentredShape(int x, int y) {
  /* We have to flip y for the GL co-ordinates*/
  return m_poly.containsPoint(QPoint(x, -y), Qt::OddEvenFill);
}
