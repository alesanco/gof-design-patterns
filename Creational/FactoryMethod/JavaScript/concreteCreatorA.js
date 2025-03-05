// concreteCreatorA.js
const Creator = require("./creator");
const ConcreteProductA = require("./concreteProductA");

class ConcreteCreatorA extends Creator {
  createProduct() {
    return new ConcreteProductA();
  }
}

module.exports = ConcreteCreatorA;
