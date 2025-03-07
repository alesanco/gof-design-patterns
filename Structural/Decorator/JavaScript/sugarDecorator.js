// sugarDecorator.js

const CoffeeDecorator = require("./coffeeDecorator");

class SugarDecorator extends CoffeeDecorator {
  getDescription() {
    return this.decoratedCoffee.getDescription() + ", Sugar";
  }

  getCost() {
    return this.decoratedCoffee.getCost() + 0.5;
  }
}

module.exports = SugarDecorator;
