// Square.cpp

#include "Square.h"
#include <iostream>

Square::Square(const std::string& color, int sideLength) : Shape(color), sideLength(sideLength) {}

void Square::setSideLength(int newSideLength) {
  sideLength = newSideLength;
}

int Square::getSideLength() const {
  return sideLength;
}

void Square::draw() const {
  std::cout << "Drawing a " << getColor() << " Square with side length " << sideLength << std::endl;
}

Square* Square::clone() const {
  return new Square(*this);
}
