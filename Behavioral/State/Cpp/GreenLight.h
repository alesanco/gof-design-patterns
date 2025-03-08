// GreenLight.h

#ifndef GREENLIGHT_H
#define GREENLIGHT_H

#include "TrafficLightState.h"
#include "TrafficLight.h"
#include "YellowLight.h"
#include <iostream>

class GreenLight : public TrafficLightState {
public:
  void handle(TrafficLight* trafficLight) override;
};

#endif // GREENLIGHT_H
