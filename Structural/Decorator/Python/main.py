# main.py

from simple_coffee import SimpleCoffee
from milk_decorator import MilkDecorator
from sugar_decorator import SugarDecorator

if __name__ == "__main__":
  basic_coffee = SimpleCoffee()
  print(f"{basic_coffee.get_description()} -> ${basic_coffee.get_cost()}")

  milk_coffee = MilkDecorator(basic_coffee)
  print(f"{milk_coffee.get_description()} -> ${milk_coffee.get_cost()}")

  sugar_milk_coffee = SugarDecorator(milk_coffee)
  print(f"{sugar_milk_coffee.get_description()} -> ${sugar_milk_coffee.get_cost()}")
