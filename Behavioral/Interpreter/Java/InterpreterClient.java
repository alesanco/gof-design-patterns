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
