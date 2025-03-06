// CarBuilder.h

#ifndef CAR_BUILDER_H
#define CAR_BUILDER_H

#include "ICarBuilder.h"

class CarBuilder : public ICarBuilder {
private:
  std::string engine = "Unknown Engine";
  bool hasGPS = false;
  bool hasSunroof = false;
  std::string seats = "Standard";

public:
  ICarBuilder* setEngine(const std::string& engine) override;
  ICarBuilder* setGPS(bool hasGPS) override;
  ICarBuilder* setSunroof(bool hasSunroof) override;
  ICarBuilder* setSeats(const std::string& seats) override;
  Car* build() override;
};

#endif // CAR_BUILDER_H
