// renderVisitor.js

const ShapeVisitor = require("./shapeVisitor");

class RenderVisitor extends ShapeVisitor {
  visitCircle(circle) {
    console.log("Rendering a Circle.");
  }

  visitSquare(square) {
    console.log("Rendering a Square.");
  }
}

module.exports = RenderVisitor;
