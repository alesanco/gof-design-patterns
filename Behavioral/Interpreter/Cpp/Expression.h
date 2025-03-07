// Expression.h

#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
  virtual int interpret() = 0;
  virtual ~Expression() = default;
};

#endif // EXPRESSION_H
