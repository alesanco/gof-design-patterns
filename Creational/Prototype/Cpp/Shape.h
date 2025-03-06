// Shape.h

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
protected:
  std::string color;

public:
  Shape(const std::string& color);
  virtual ~Shape() = default;

  void setColor(const std::string& newColor);
  std::string getColor() const;

  virtual Shape* clone() const = 0;
  virtual void draw() const = 0;
};

#endif // SHAPE_H
