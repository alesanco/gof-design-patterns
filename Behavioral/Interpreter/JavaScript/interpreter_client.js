// interpreter_client.js

const NumberExpression = require("./number_expression");
const AddExpression = require("./add_expression");
const SubtractExpression = require("./subtract_expression");

function parseExpression(expression) {
  const stack = [];
  const tokens = expression.split(" ");

  for (const token of tokens) {
    if (token === "+") {
      const right = stack.pop();
      const left = stack.pop();
      stack.push(new AddExpression(left, right));
    } else if (token === "-") {
      const right = stack.pop();
      const left = stack.pop();
      stack.push(new SubtractExpression(left, right));
    } else {
      stack.push(new NumberExpression(parseInt(token, 10)));
    }
  }

  return stack.pop();
}

module.exports = parseExpression;
