// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"

class Circle : public IShape {
public:
  void draw() override;
};

#endif // CIRCLE_H
