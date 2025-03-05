// main.js
const ConcreteCreatorA = require("./concreteCreatorA");
const ConcreteCreatorB = require("./concreteCreatorB");

const creatorA = new ConcreteCreatorA();
const productA = creatorA.createProduct();
productA.use();

const creatorB = new ConcreteCreatorB();
const productB = creatorB.createProduct();
productB.use();
