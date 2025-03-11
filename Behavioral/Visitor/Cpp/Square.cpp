// Square.cpp

#include "Square.h"

void Square::accept(ShapeVisitor& visitor) {
  visitor.visit(*this);
}
