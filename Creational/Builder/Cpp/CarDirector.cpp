// CarDirector.cpp
#include "CarDirector.h"

Car* CarDirector::buildLuxuryCar() {
  return (new CarBuilder())
          ->setEngine("V8 Turbo")
          ->setGPS(true)
          ->setSunroof(true)
          ->setSeats("Leather")
          ->build();
}

Car* CarDirector::buildEconomyCar() {
  return (new CarBuilder())
          ->setEngine("1.6L Petrol")
          ->setGPS(false)
          ->setSunroof(false)
          ->setSeats("Standard")
          ->build();
}
