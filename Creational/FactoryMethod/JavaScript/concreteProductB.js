const Product = require("./product");

class ConcreteProductB extends Product {
  use() {
    console.log("Using Product B");
  }
}

module.exports = ConcreteProductB;
