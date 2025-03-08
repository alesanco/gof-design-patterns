// RedLight.h

#ifndef REDLIGHT_H
#define REDLIGHT_H

#include "TrafficLightState.h"
#include "TrafficLight.h"
#include "GreenLight.h"
#include <iostream>

class RedLight : public TrafficLightState {
public:
  void handle(TrafficLight* trafficLight) override;
};

#endif // REDLIGHT_H
