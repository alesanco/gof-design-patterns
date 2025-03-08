// YellowLight.h

#ifndef YELLOWLIGHT_H
#define YELLOWLIGHT_H

#include "TrafficLightState.h"
#include "TrafficLight.h"
#include "RedLight.h"
#include <iostream>

class YellowLight : public TrafficLightState {
public:
  void handle(TrafficLight* trafficLight) override;
};

#endif // YELLOWLIGHT_H
