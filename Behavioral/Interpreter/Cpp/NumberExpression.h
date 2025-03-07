// NumberExpression.h

#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

#include "Expression.h"

class NumberExpression : public Expression {
private:
  int number;

public:
  explicit NumberExpression(int number) : number(number) {}
  int interpret() override { return number; }
};

#endif // NUMBER_EXPRESSION_H
