// AddExpression.h

#ifndef ADD_EXPRESSION_H
#define ADD_EXPRESSION_H

#include "Expression.h"

class AddExpression : public Expression {
private:
  Expression *left, *right;

public:
  AddExpression(Expression* left, Expression* right) : left(left), right(right) {}
  
  int interpret() override {
    return left->interpret() + right->interpret();
  }

  ~AddExpression() {
    delete left;
    delete right;
  }
};

#endif // ADD_EXPRESSION_H
