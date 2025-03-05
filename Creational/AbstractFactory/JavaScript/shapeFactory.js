// shapeFactory.js
class ShapeFactory {
  createShape(shapeType) {
    throw new Error("Method 'createShape()' must be implemented.");
  }

  createRenderer() {
    throw new Error("Method 'createRenderer()' must be implemented.");
  }
}

module.exports = ShapeFactory;
