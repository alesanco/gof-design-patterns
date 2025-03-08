// TrafficLight.cpp

#include "TrafficLight.h"
#include "RedLight.h"

TrafficLight::TrafficLight() {
  state = new RedLight(); // Initial state
}

TrafficLight::~TrafficLight() {
  delete state;
}

void TrafficLight::setState(TrafficLightState* newState) {
  delete state;
  state = newState;
}

void TrafficLight::change() {
  state->handle(this);
}
