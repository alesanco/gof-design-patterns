# coffee_decorator.py

from coffee import Coffee

class CoffeeDecorator(Coffee):
  def __init__(self, coffee: Coffee):
    self._decorated_coffee = coffee

  def get_description(self) -> str:
    return self._decorated_coffee.get_description()

  def get_cost(self) -> float:
    return self._decorated_coffee.get_cost()
