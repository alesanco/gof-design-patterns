# main.py

from interpreter_client import parse_expression

if __name__ == "__main__":
  expression = "5 3 + 2 -"  # Equivalent to (5 + 3 - 2)
  
  parsed_expression = parse_expression(expression)
  result = parsed_expression.interpret()
  
  print("Result:", result)  # Output: 6
