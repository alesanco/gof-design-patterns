# number_expression.py

from expression import Expression

class NumberExpression(Expression):
  def __init__(self, number):
    self.number = number

  def interpret(self):
    return self.number
