// coffeeDecorator.js

const Coffee = require("./coffee");

class CoffeeDecorator extends Coffee {
  constructor(coffee) {
    super();
    this.decoratedCoffee = coffee;
  }

  getDescription() {
    return this.decoratedCoffee.getDescription();
  }

  getCost() {
    return this.decoratedCoffee.getCost();
  }
}

module.exports = CoffeeDecorator;
