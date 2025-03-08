// TrafficLight.h

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "TrafficLightState.h"

class TrafficLight {
private:
  TrafficLightState* state;

public:
  TrafficLight();
  ~TrafficLight();
  void setState(TrafficLightState* newState);
  void change();
};

#endif // TRAFFICLIGHT_H
