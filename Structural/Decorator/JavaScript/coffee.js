// coffee.js

class Coffee {
  getDescription() {
    throw new Error("Method 'getDescription()' must be implemented.");
  }

  getCost() {
    throw new Error("Method 'getCost()' must be implemented.");
  }
}

module.exports = Coffee;
