// CarBuilder.cpp

#include "CarBuilder.h"

ICarBuilder* CarBuilder::setEngine(const std::string& engine) {
  this->engine = engine;
  return this;
}

ICarBuilder* CarBuilder::setGPS(bool hasGPS) {
  this->hasGPS = hasGPS;
  return this;
}

ICarBuilder* CarBuilder::setSunroof(bool hasSunroof) {
  this->hasSunroof = hasSunroof;
  return this;
}

ICarBuilder* CarBuilder::setSeats(const std::string& seats) {
  this->seats = seats;
  return this;
}

Car* CarBuilder::build() {
  return new Car(engine, hasGPS, hasSunroof, seats);
}
