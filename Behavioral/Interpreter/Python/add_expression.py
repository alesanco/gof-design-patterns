# add_expression.py

from expression import Expression

class AddExpression(Expression):
  def __init__(self, left, right):
    self.left = left
    self.right = right

  def interpret(self):
    return self.left.interpret() + self.right.interpret()
