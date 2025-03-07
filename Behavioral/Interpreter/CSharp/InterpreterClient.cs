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
