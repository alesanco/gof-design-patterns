// exportVisitor.js

const ShapeVisitor = require("./shapeVisitor");

class ExportVisitor extends ShapeVisitor {
  visitCircle(circle) {
    console.log("Exporting a Circle to file.");
  }

  visitSquare(square) {
    console.log("Exporting a Square to file.");
  }
}

module.exports = ExportVisitor;
