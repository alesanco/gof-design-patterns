// twoDShapeFactory.js

const ShapeFactory = require("./shapeFactory");
const ShapeType = require("./shapeType");
const Circle = require("./circle");
const Square = require("./square");
const TwoDRenderer = require("./twoDRenderer");

class TwoDShapeFactory extends ShapeFactory {
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
    return new TwoDRenderer();
  }
}

module.exports = TwoDShapeFactory;
