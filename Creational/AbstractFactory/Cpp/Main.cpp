// Main.cpp

#include <iostream>
#include "RenderMode.h"
#include "ShapeType.h"
#include "IShapeFactory.h"
#include "TwoDShapeFactory.h"
#include "ThreeDShapeFactory.h"

int main() {
  for (RenderMode mode : {RenderMode::TWO_D, RenderMode::THREE_D}) {
    IShapeFactory* factory;

    switch (mode) {
      case RenderMode::TWO_D:
        factory = new TwoDShapeFactory();
        break;
      case RenderMode::THREE_D:
        factory = new ThreeDShapeFactory();
        break;
      default:
        throw std::invalid_argument("Unknown render mode");
    }

    for (ShapeType shapeType : {ShapeType::CIRCLE, ShapeType::SQUARE}) {
      std::cout << "\n=== Mode: " << (mode == RenderMode::TWO_D ? "TWO_D" : "THREE_D") 
                << ", Shape: " << (shapeType == ShapeType::CIRCLE ? "CIRCLE" : "SQUARE") << " ===\n";

      IShape* shape = factory->createShape(shapeType);
      IRenderer* renderer = factory->createRenderer();

      shape->draw();
      renderer->render();

      delete shape;
      delete renderer;
    }

    delete factory;
  }

  return 0;
}
