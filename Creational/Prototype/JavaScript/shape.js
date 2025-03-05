// shape.js
class Shape {
  constructor(color) {
    this.color = color;
  }

  setColor(newColor) {
    this.color = newColor;
  }

  getColor() {
    return this.color;
  }

  clone() {
    return Object.assign(Object.create(Object.getPrototypeOf(this)), this);
  }

  draw() {
    throw new Error("Subclass must implement abstract method");
  }
}

module.exports = Shape;
