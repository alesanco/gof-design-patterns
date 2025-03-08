// YellowLight.cpp

#include "YellowLight.h"

void YellowLight::handle(TrafficLight* trafficLight) {
  std::cout << "Yellow Light - PREPARE!" << std::endl;
  trafficLight->setState(new RedLight()); // Transition to Red
}
