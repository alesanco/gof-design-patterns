// main.js

const SimpleCoffee = require("./simpleCoffee");
const MilkDecorator = require("./milkDecorator");
const SugarDecorator = require("./sugarDecorator");

const basicCoffee = new SimpleCoffee();
console.log(`${basicCoffee.getDescription()} -> $${basicCoffee.getCost()}`);

const milkCoffee = new MilkDecorator(basicCoffee);
console.log(`${milkCoffee.getDescription()} -> $${milkCoffee.getCost()}`);

const sugarMilkCoffee = new SugarDecorator(milkCoffee);
console.log(`${sugarMilkCoffee.getDescription()} -> $${sugarMilkCoffee.getCost()}`);
