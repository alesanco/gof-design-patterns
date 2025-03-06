// main.js

const logger1 = require("./logger");
logger1.log("Initializing the system...");

const logger2 = require("./logger");
logger2.log("System running.");

// Verify if both instances are the same
console.log(`Logger instances are the same: ${logger1 === logger2}`);
