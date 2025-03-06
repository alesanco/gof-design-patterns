# car_builder.py

from car import Car

class CarBuilder:
  def __init__(self):
    self.engine = "Unknown Engine"
    self.has_gps = False
    self.has_sunroof = False
    self.seats = "Standard"

  def set_engine(self, engine):
    self.engine = engine
    return self

  def set_gps(self, has_gps):
    self.has_gps = has_gps
    return self

  def set_sunroof(self, has_sunroof):
    self.has_sunroof = has_sunroof
    return self

  def set_seats(self, seats):
    self.seats = seats
    return self

  def build(self):
    return Car(self.engine, self.has_gps, self.has_sunroof, self.seats)
