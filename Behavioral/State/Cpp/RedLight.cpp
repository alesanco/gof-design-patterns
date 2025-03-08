// RedLight.cpp

#include "RedLight.h"

void RedLight::handle(TrafficLight* trafficLight) {
  std::cout << "Red Light - STOP!" << std::endl;
  trafficLight->setState(new GreenLight()); // Transition to Green
}
