// simpleCoffee.js

const Coffee = require("./coffee");

class SimpleCoffee extends Coffee {
  getDescription() {
    return "Simple Coffee";
  }

  getCost() {
    return 5.0;
  }
}

module.exports = SimpleCoffee;
