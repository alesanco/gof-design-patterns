// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
  int radius;

public:
  Circle(const std::string& color, int radius);
  void setRadius(int newRadius);
  int getRadius() const;
  void draw() const override;
  Circle* clone() const override;
};

#endif // CIRCLE_H
