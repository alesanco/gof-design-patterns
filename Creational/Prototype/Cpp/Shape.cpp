// Shape.cpp
#include "Shape.h"

Shape::Shape(const std::string& color) : color(color) {}

void Shape::setColor(const std::string& newColor) {
  color = newColor;
}

std::string Shape::getColor() const {
  return color;
}
