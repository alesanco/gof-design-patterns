// Square.h
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
  int sideLength;

public:
  Square(const std::string& color, int sideLength);
  void setSideLength(int newSideLength);
  int getSideLength() const;
  void draw() const override;
  Square* clone() const override;
};

#endif // SQUARE_H
