// Main.cpp

#include "InterpreterClient.h"
#include <iostream>

int main() {
  std::string expression = "5 3 + 2 -"; // Equivalent to (5 + 3 - 2)
  
  Expression* parsedExpression = InterpreterClient::parseExpression(expression);
  int result = parsedExpression->interpret();
  
  std::cout << "Result: " << result << std::endl; // Output: 6

  delete parsedExpression; // Clean up memory
  return 0;
}
