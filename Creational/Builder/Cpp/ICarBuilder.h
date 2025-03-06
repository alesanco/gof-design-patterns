// ICarBuilder.h

#ifndef I_CAR_BUILDER_H
#define I_CAR_BUILDER_H

#include "Car.h"

class ICarBuilder {
public:
  virtual ~ICarBuilder() = default;
  virtual ICarBuilder* setEngine(const std::string& engine) = 0;
  virtual ICarBuilder* setGPS(bool hasGPS) = 0;
  virtual ICarBuilder* setSunroof(bool hasSunroof) = 0;
  virtual ICarBuilder* setSeats(const std::string& seats) = 0;
  virtual Car* build() = 0;
};

#endif // I_CAR_BUILDER_H
