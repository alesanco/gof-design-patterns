// number_expression.js

const Expression = require("./expression");

class NumberExpression extends Expression {
  constructor(number) {
    super();
    this.number = number;
  }

  interpret() {
    return this.number;
  }
}

module.exports = NumberExpression;
