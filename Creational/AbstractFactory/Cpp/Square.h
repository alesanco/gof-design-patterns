// Square.h

#ifndef SQUARE_H
#define SQUARE_H

#include "IShape.h"

class Square : public IShape {
public:
  void draw() override;
};

#endif // SQUARE_H
