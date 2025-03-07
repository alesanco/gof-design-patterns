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
