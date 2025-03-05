# main.py
from car_director import CarDirector

if __name__ == "__main__":
  director = CarDirector()

  # Build a Luxury Car
  luxury_car = director.build_luxury_car()
  print("\nLuxury Car:")
  luxury_car.show_specifications()

  # Build an Economy Car
  economy_car = director.build_economy_car()
  print("\nEconomy Car:")
  economy_car.show_specifications()
