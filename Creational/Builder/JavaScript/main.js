// main.js

const CarDirector = require("./carDirector");
const director = new CarDirector();

// Build a Luxury Car
const luxuryCar = director.buildLuxuryCar();
console.log("\nLuxury Car:");
luxuryCar.showSpecifications();

// Build an Economy Car
const economyCar = director.buildEconomyCar();
console.log("\nEconomy Car:");
economyCar.showSpecifications();
