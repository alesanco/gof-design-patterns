# car.py
class Car:
  def __init__(self, engine, has_gps, has_sunroof, seats):
    self.engine = engine
    self.has_gps = has_gps
    self.has_sunroof = has_sunroof
    self.seats = seats

  def show_specifications(self):
    print("Car Specifications:")
    print(f"Engine: {self.engine}")
    print(f"GPS: {'Yes' if self.has_gps else 'No'}")
    print(f"Sunroof: {'Yes' if self.has_sunroof else 'No'}")
    print(f"Seats: {self.seats}")
