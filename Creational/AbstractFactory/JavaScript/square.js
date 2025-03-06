// square.js

const Shape = require("./shape");

class Square extends Shape {
  draw() {
    console.log("Drawing a Square");
  }
}

module.exports = Square;
