// Car.h

#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
  std::string engine;
  bool hasGPS;
  bool hasSunroof;
  std::string seats;

public:
  Car(std::string engine, bool hasGPS, bool hasSunroof, std::string seats);
  void showSpecifications();
};

#endif // CAR_H
