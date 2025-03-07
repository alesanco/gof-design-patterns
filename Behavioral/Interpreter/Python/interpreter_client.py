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
