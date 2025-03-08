// GreenLight.cpp

#include "GreenLight.h"

void GreenLight::handle(TrafficLight* trafficLight) {
  std::cout << "Green Light - GO!" << std::endl;
  trafficLight->setState(new YellowLight()); // Transition to Yellow
}
