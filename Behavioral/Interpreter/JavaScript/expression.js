// expression.js

class Expression {
  interpret() {
    throw new Error("interpret() must be implemented by subclasses");
  }
}

module.exports = Expression;
