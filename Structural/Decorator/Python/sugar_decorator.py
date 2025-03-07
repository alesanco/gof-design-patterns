# sugar_decorator.py

from coffee_decorator import CoffeeDecorator

class SugarDecorator(CoffeeDecorator):
  def get_description(self) -> str:
    return self._decorated_coffee.get_description() + ", Sugar"

  def get_cost(self) -> float:
    return self._decorated_coffee.get_cost() + 0.5
