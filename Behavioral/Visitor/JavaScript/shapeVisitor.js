// shapeVisitor.js

class ShapeVisitor {
  visitCircle(circle) {
    throw new Error("Method 'visitCircle()' must be implemented.");
  }

  visitSquare(square) {
    throw new Error("Method 'visitSquare()' must be implemented.");
  }
}

module.exports = ShapeVisitor;
