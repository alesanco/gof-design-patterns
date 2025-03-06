// CarDirector.h

#ifndef CAR_DIRECTOR_H
#define CAR_DIRECTOR_H

#include "CarBuilder.h"

class CarDirector {
public:
  Car* buildLuxuryCar();
  Car* buildEconomyCar();
};

#endif // CAR_DIRECTOR_H
