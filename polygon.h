#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include <QVector>
#include <QPoint>
#include <Qt>

class polygon : public shape {
public:
  polygon(const QColor &colour, const QColor &selectedColour,
          const QVector<QPoint> vertices);

private:
  virtual void drawShape();
  virtual bool insideZeroCentredShape(int x, int y);

  QPolygon m_poly;
};


#endif
