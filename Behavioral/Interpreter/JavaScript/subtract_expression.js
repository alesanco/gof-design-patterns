// subtract_expression.js

const Expression = require("./expression");

class SubtractExpression extends Expression {
  constructor(left, right) {
    super();
    this.left = left;
    this.right = right;
  }

  interpret() {
    return this.left.interpret() - this.right.interpret();
  }
}

module.exports = SubtractExpression;
