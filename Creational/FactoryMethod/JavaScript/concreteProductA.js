// concreteProductA.js

const Product = require("./product");

class ConcreteProductA extends Product {
  use() {
    console.log("Using Product A");
  }
}

module.exports = ConcreteProductA;
