// ThreeDShapeFactory.cpp
#include "ThreeDShapeFactory.h"
#include "Circle.h"
#include "Square.h"
#include "ThreeDRenderer.h"
#include <stdexcept>

IShape* ThreeDShapeFactory::createShape(ShapeType type) {
  switch (type) {
    case ShapeType::CIRCLE:
      return new Circle();
    case ShapeType::SQUARE:
      return new Square();
    default:
      throw std::invalid_argument("Unknown shape type");
  }
}

IRenderer* ThreeDShapeFactory::createRenderer() {
  return new ThreeDRenderer();
}
