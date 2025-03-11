// circle.js

const Shape = require("./shape");

class Circle extends Shape {
  accept(visitor) {
    visitor.visitCircle(this);
  }
}

module.exports = Circle;
