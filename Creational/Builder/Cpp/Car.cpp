// Car.cpp
#include "Car.h"
#include <iostream>

Car::Car(std::string engine, bool hasGPS, bool hasSunroof, std::string seats)
  : engine(engine), hasGPS(hasGPS), hasSunroof(hasSunroof), seats(seats) {}

void Car::showSpecifications() {
  std::cout << "Car Specifications:\n";
  std::cout << "Engine: " << engine << std::endl;
  std::cout << "GPS: " << (hasGPS ? "Yes" : "No") << std::endl;
  std::cout << "Sunroof: " << (hasSunroof ? "Yes" : "No") << std::endl;
  std::cout << "Seats: " << seats << std::endl;
}
