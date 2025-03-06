// circle.js

const Shape = require("./shape");

class Circle extends Shape {
  draw() {
    console.log("Drawing a Circle");
  }
}

module.exports = Circle;
