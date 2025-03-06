// TwoDShapeFactory.cpp

#include "TwoDShapeFactory.h"
#include "Circle.h"
#include "Square.h"
#include "TwoDRenderer.h"
#include <stdexcept>

IShape* TwoDShapeFactory::createShape(ShapeType type) {
  switch (type) {
    case ShapeType::CIRCLE:
      return new Circle();
    case ShapeType::SQUARE:
      return new Square();
    default:
      throw std::invalid_argument("Unknown shape type");
  }
}

IRenderer* TwoDShapeFactory::createRenderer() {
  return new TwoDRenderer();
}
