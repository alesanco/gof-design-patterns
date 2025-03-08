// Main.cpp

#include "TrafficLight.h"

int main() {
  TrafficLight trafficLight;

  for (int i = 0; i < 6; i++) {
    trafficLight.change();
  }

  return 0;
}
