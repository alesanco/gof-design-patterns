// InterpreterClient.h

#ifndef INTERPRETER_CLIENT_H
#define INTERPRETER_CLIENT_H

#include "Expression.h"
#include <string>

class InterpreterClient {
public:
  static Expression* parseExpression(const std::string& expression);
};

#endif // INTERPRETER_CLIENT_H
