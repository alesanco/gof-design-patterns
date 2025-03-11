// Square.h

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
public:
  void accept(ShapeVisitor& visitor) override;
};

#endif // SQUARE_H
