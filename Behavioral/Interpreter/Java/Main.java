// Main.java

public class Main {
  public static void main(String[] args) {
    String expression = "5 3 + 2 -"; // Equivalent to (5 + 3 - 2)
    
    Expression parsedExpression = InterpreterClient.parseExpression(expression);
    int result = parsedExpression.interpret();
    
    System.out.println("Result: " + result); // Output: 6
  }
}
