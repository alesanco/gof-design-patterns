# Interpreter Pattern

## 📌 What is the Interpreter Pattern?
The **Interpreter Pattern** is a behavioral design pattern that **defines a way to evaluate sentences in a language** by **using a grammatical representation** and **an interpreter** to process it. It is often used in parsing expressions, implementing domain-specific languages (DSLs), or evaluating math expressions.

## 📌 When to Use Interpreter
Use the **Interpreter pattern** when:

- You need to evaluate expressions based on a defined **grammar or set of rules**.
- Implementing a **language interpreter, command processor, or math expression evaluator**.
- Processing structured inputs where **recursion and parsing techniques** are required.

## 📌 Example: Mathematical Expression Interpreter
We implement an **expression evaluator** that can parse and evaluate mathematical expressions in **postfix notation** (Reverse Polish Notation).

## 📌 Implementation in Different Languages
Each language implements the **Interpreter pattern** differently based on its capabilities.

### **Java Implementation**
```java
// Expression.java

public interface Expression {
  int interpret();
}
```
```java
// NumberExpression.java

public class NumberExpression implements Expression {
  private int number;

  public NumberExpression(int number) {
    this.number = number;
  }

  @Override
  public int interpret() {
    return number;
  }
}
```
```java
// AddExpression.java

public class AddExpression implements Expression {
  private Expression left, right;

  public AddExpression(Expression left, Expression right) {
    this.left = left;
    this.right = right;
  }

  @Override
  public int interpret() {
    return left.interpret() + right.interpret();
  }
}
```
```java
// SubtractExpression.java

public class SubtractExpression implements Expression {
  private Expression left, right;

  public SubtractExpression(Expression left, Expression right) {
    this.left = left;
    this.right = right;
  }

  @Override
  public int interpret() {
    return left.interpret() - right.interpret();
  }
}
```
```java
// InterpreterClient.java

import java.util.Stack;

public class InterpreterClient {
  public static Expression parseExpression(String expression) {
    Stack<Expression> stack = new Stack<>();

    String[] tokens = expression.split(" ");
    for (String token : tokens) {
      if (token.equals("+")) {
        Expression right = stack.pop();
        Expression left = stack.pop();
        stack.push(new AddExpression(left, right));
      } else if (token.equals("-")) {
        Expression right = stack.pop();
        Expression left = stack.pop();
        stack.push(new SubtractExpression(left, right));
      } else {
        stack.push(new NumberExpression(Integer.parseInt(token)));
      }
    }
    return stack.pop();
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    String expression = "5 3 + 2 -"; // Equivalent to (5 + 3 - 2)
    
    Expression parsedExpression = InterpreterClient.parseExpression(expression);
    int result = parsedExpression.interpret();
    
    System.out.println("Result: " + result); // Output: 6
  }
}
```

### **C# Implementation**
```csharp
// IExpression.cs

public interface IExpression {
  int Interpret();
}
```
```csharp
// NumberExpression.cs

public class NumberExpression : IExpression {
  private readonly int _number;

  public NumberExpression(int number) {
    _number = number;
  }

  public int Interpret() {
    return _number;
  }
}
```
```csharp
// AddExpression.cs

public class AddExpression : IExpression {
  private readonly IExpression _left, _right;

  public AddExpression(IExpression left, IExpression right) {
    _left = left;
    _right = right;
  }

  public int Interpret() {
    return _left.Interpret() + _right.Interpret();
  }
}
```
```csharp
// SubtractExpression.cs

public class SubtractExpression : IExpression {
  private readonly IExpression _left, _right;

  public SubtractExpression(IExpression left, IExpression right) {
    _left = left;
    _right = right;
  }

  public int Interpret() {
    return _left.Interpret() - _right.Interpret();
  }
}
```
```csharp
// InterpreterClient.cs

using System;
using System.Collections.Generic;

public class InterpreterClient {
  public static IExpression ParseExpression(string expression) {
    Stack<IExpression> stack = new Stack<IExpression>();

    string[] tokens = expression.Split(' ');
    foreach (string token in tokens) {
      if (token == "+") {
        IExpression right = stack.Pop();
        IExpression left = stack.Pop();
        stack.Push(new AddExpression(left, right));
      } else if (token == "-") {
        IExpression right = stack.Pop();
        IExpression left = stack.Pop();
        stack.Push(new SubtractExpression(left, right));
      } else {
        stack.Push(new NumberExpression(int.Parse(token)));
      }
    }
    return stack.Pop();
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    string expression = "5 3 + 2 -"; // Equivalent to (5 + 3 - 2)
    
    IExpression parsedExpression = InterpreterClient.ParseExpression(expression);
    int result = parsedExpression.Interpret();
    
    Console.WriteLine("Result: " + result); // Output: 6
  }
}

```

### **C++ Implementation**
```cpp
// Expression.h

#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
  virtual int interpret() = 0;
  virtual ~Expression() = default;
};

#endif // EXPRESSION_H
```
```cpp
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
```
```cpp
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
```
```cpp
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
```
```cpp
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
```
```cpp
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
```
```cpp
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
```

### **Python Implementation**
```python
# expression.py

from abc import ABC, abstractmethod

class Expression(ABC):
  @abstractmethod
  def interpret(self):
    pass
```
```python
# number_expression.py

from expression import Expression

class NumberExpression(Expression):
  def __init__(self, number):
    self.number = number

  def interpret(self):
    return self.number
```
```python
# add_expression.py

from expression import Expression

class AddExpression(Expression):
  def __init__(self, left, right):
    self.left = left
    self.right = right

  def interpret(self):
    return self.left.interpret() + self.right.interpret()
```
```python
# subtract_expression.py

from expression import Expression

class SubtractExpression(Expression):
  def __init__(self, left, right):
    self.left = left
    self.right = right

  def interpret(self):
    return self.left.interpret() - self.right.interpret()
```
```python
# interpreter_client.py

from number_expression import NumberExpression
from add_expression import AddExpression
from subtract_expression import SubtractExpression

def parse_expression(expression):
  stack = []
  tokens = expression.split()

  for token in tokens:
    if token == "+":
      right = stack.pop()
      left = stack.pop()
      stack.append(AddExpression(left, right))
    elif token == "-":
      right = stack.pop()
      left = stack.pop()
      stack.append(SubtractExpression(left, right))
    else:
      stack.append(NumberExpression(int(token)))

  return stack.pop()
```
```python
# main.py

from interpreter_client import parse_expression

if __name__ == "__main__":
  expression = "5 3 + 2 -"  # Equivalent to (5 + 3 - 2)
  
  parsed_expression = parse_expression(expression)
  result = parsed_expression.interpret()
  
  print("Result:", result)  # Output: 6
```

### **JavaScript Implementation**
```javascript
// expression.js

class Expression {
  interpret() {
    throw new Error("interpret() must be implemented by subclasses");
  }
}

module.exports = Expression;
```
```javascript
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
```
```javascript
// add_expression.js

const Expression = require("./expression");

class AddExpression extends Expression {
  constructor(left, right) {
    super();
    this.left = left;
    this.right = right;
  }

  interpret() {
    return this.left.interpret() + this.right.interpret();
  }
}

module.exports = AddExpression;
```
```javascript
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
```
```javascript
// interpreter_client.js

const NumberExpression = require("./number_expression");
const AddExpression = require("./add_expression");
const SubtractExpression = require("./subtract_expression");

function parseExpression(expression) {
  const stack = [];
  const tokens = expression.split(" ");

  for (const token of tokens) {
    if (token === "+") {
      const right = stack.pop();
      const left = stack.pop();
      stack.push(new AddExpression(left, right));
    } else if (token === "-") {
      const right = stack.pop();
      const left = stack.pop();
      stack.push(new SubtractExpression(left, right));
    } else {
      stack.push(new NumberExpression(parseInt(token, 10)));
    }
  }

  return stack.pop();
}

module.exports = parseExpression;
```
```javascript
// main.js

const parseExpression = require("./interpreter_client");

const expression = "5 3 + 2 -"; // Equivalent to (5 + 3 - 2)
const parsedExpression = parseExpression(expression);
const result = parsedExpression.interpret();

console.log("Result:", result); // Output: 6
```

## 📌 Running the Code
To test the **Interpreter pattern**, run the following commands:

### **Java**
```sh
cd Behavioral/Interpreter/Java
javac *.java
java Main
```

### **C#**
```sh
cd Behavioral/Interpreter/CSharp
dotnet build
dotnet run
```

### **C++**
```sh
cd Behavioral/Interpreter/Cpp
g++ *.cpp -o interpreter
./interpreter
```

### **Python**
```sh
cd Behavioral/Interpreter/Python
python3 main.py
```

### **JavaScript**
```sh
cd Behavioral/Interpreter/JavaScript
node main.js
```

## 📌 Expected Output
```
Result: 6
```

## 📌 Summary
- Encapsulates grammar rules in separate classes, making parsing modular and extensible.
- Uses recursive interpretation, enabling evaluation of nested expressions.
- Can be extended to support additional operations like multiplication, division, or variables.