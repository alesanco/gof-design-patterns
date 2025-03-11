// Circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
  void accept(ShapeVisitor& visitor) override;
};

#endif // CIRCLE_H
