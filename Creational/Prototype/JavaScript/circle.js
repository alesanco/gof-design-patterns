// circle.js
const Shape = require("./shape");

class Circle extends Shape {
  constructor(color, radius) {
    super(color);
    this.radius = radius;
  }

  setRadius(newRadius) {
    this.radius = newRadius;
  }

  getRadius() {
    return this.radius;
  }

  draw() {
    console.log(`Drawing a ${this.getColor()} Circle with radius ${this.radius}`);
  }
}

module.exports = Circle;
