# car_director.py

from car_builder import CarBuilder

class CarDirector:
  def build_luxury_car(self):
    return CarBuilder()\
            .set_engine("V8 Turbo")\
            .set_gps(True)\
            .set_sunroof(True)\
            .set_seats("Leather")\
            .build()

  def build_economy_car(self):
    return CarBuilder()\
            .set_engine("1.6L Petrol")\
            .set_gps(False)\
            .set_sunroof(False)\
            .set_seats("Standard")\
            .build()
