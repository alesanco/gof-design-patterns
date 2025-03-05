// square.js
const Shape = require("./shape");

class Square extends Shape {
  constructor(color, sideLength) {
    super(color);
    this.sideLength = sideLength;
  }

  setSideLength(newSideLength) {
    this.sideLength = newSideLength;
  }

  getSideLength() {
    return this.sideLength;
  }

  draw() {
    console.log(`Drawing a ${this.getColor()} Square with side length ${this.sideLength}`);
  }
}

module.exports = Square;
