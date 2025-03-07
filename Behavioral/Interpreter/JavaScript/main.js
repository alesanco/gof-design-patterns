// main.js

const parseExpression = require("./interpreter_client");

const expression = "5 3 + 2 -"; // Equivalent to (5 + 3 - 2)
const parsedExpression = parseExpression(expression);
const result = parsedExpression.interpret();

console.log("Result:", result); // Output: 6
