// threeDShapeFactory.js

const ShapeFactory = require("./shapeFactory");
const ShapeType = require("./shapeType");
const Circle = require("./circle");
const Square = require("./square");
const ThreeDRenderer = require("./threeDRenderer");

class ThreeDShapeFactory extends ShapeFactory {
  createShape(shapeType) {
    switch (shapeType) {
      case ShapeType.CIRCLE:
        return new Circle();
      case ShapeType.SQUARE:
        return new Square();
      default:
        throw new Error(`Unknown shape type: ${shapeType}`);
    }
  }

  createRenderer() {
    return new ThreeDRenderer();
  }
}

module.exports = ThreeDShapeFactory;
