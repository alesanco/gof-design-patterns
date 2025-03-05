// main.js
const Circle = require("./circle");
const Square = require("./square");

const originalCircle = new Circle("Red", 10);
const originalSquare = new Square("Blue", 5);

// Clone the objects
const clonedCircle = originalCircle.clone();
const clonedSquare = originalSquare.clone();

// Modify cloned objects
clonedCircle.setColor("Green");
clonedCircle.setRadius(20);

clonedSquare.setColor("Yellow");
clonedSquare.setSideLength(10);

// Display original and cloned objects
console.log("Original Objects:");
originalCircle.draw();
originalSquare.draw();

console.log("\nCloned Objects:");
clonedCircle.draw();
clonedSquare.draw();
