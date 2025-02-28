const Creator = require("./creator");
const ConcreteProductB = require("./concreteProductB");

class ConcreteCreatorB extends Creator {
  createProduct() {
    return new ConcreteProductB();
  }
}

module.exports = ConcreteCreatorB;
