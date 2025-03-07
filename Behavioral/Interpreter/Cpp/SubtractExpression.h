// SubtractExpression.h

#ifndef SUBTRACT_EXPRESSION_H
#define SUBTRACT_EXPRESSION_H

#include "Expression.h"

class SubtractExpression : public Expression {
private:
  Expression *left, *right;

public:
  SubtractExpression(Expression* left, Expression* right) : left(left), right(right) {}
  
  int interpret() override {
    return left->interpret() - right->interpret();
  }

  ~SubtractExpression() {
    delete left;
    delete right;
  }
};

#endif // SUBTRACT_EXPRESSION_H
