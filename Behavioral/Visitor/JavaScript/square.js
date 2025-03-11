// square.js

const Shape = require("./shape");

class Square extends Shape {
  accept(visitor) {
    visitor.visitSquare(this);
  }
}

module.exports = Square;
