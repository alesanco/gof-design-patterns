// Circle.cpp
#include "Circle.h"
#include <iostream>

Circle::Circle(const std::string& color, int radius) : Shape(color), radius(radius) {}

void Circle::setRadius(int newRadius) {
  radius = newRadius;
}

int Circle::getRadius() const {
  return radius;
}

void Circle::draw() const {
  std::cout << "Drawing a " << getColor() << " Circle with radius " << radius << std::endl;
}

Circle* Circle::clone() const {
  return new Circle(*this);
}
