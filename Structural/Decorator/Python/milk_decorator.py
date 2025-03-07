# milk_decorator.py

from coffee_decorator import CoffeeDecorator

class MilkDecorator(CoffeeDecorator):
  def get_description(self) -> str:
    return self._decorated_coffee.get_description() + ", Milk"

  def get_cost(self) -> float:
    return self._decorated_coffee.get_cost() + 1.5
