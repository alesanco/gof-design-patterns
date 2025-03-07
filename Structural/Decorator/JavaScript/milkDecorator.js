// milkDecorator.js

const CoffeeDecorator = require("./coffeeDecorator");

class MilkDecorator extends CoffeeDecorator {
  getDescription() {
    return this.decoratedCoffee.getDescription() + ", Milk";
  }

  getCost() {
    return this.decoratedCoffee.getCost() + 1.5;
  }
}

module.exports = MilkDecorator;
