// InterpreterClient.cpp

#include "InterpreterClient.h"
#include "NumberExpression.h"
#include "AddExpression.h"
#include "SubtractExpression.h"
#include <stack>
#include <sstream>

Expression* InterpreterClient::parseExpression(const std::string& expression) {
  std::stack<Expression*> stack;
  std::istringstream iss(expression);
  std::string token;

  while (iss >> token) {
    if (token == "+") {
      Expression* right = stack.top(); stack.pop();
      Expression* left = stack.top(); stack.pop();
      stack.push(new AddExpression(left, right));
    } else if (token == "-") {
      Expression* right = stack.top(); stack.pop();
      Expression* left = stack.top(); stack.pop();
      stack.push(new SubtractExpression(left, right));
    } else {
      stack.push(new NumberExpression(std::stoi(token)));
    }
  }

  return stack.top();
}
