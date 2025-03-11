// Shape.h

#ifndef SHAPE_H
#define SHAPE_H

#include "ShapeVisitor.h"

class Shape {
public:
  virtual void accept(ShapeVisitor& visitor) = 0;
  virtual ~Shape() = default;
};

#endif // SHAPE_H
