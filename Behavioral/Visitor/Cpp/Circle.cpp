// Circle.cpp

#include "Circle.h"

void Circle::accept(ShapeVisitor& visitor) {
  visitor.visit(*this);
}
