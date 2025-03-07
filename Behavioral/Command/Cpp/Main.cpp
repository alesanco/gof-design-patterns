// Main.cpp

#include "Light.h"
#include "TurnOnCommand.h"
#include "TurnOffCommand.h"
#include "RemoteControl.h"

int main() {
  Light light;
  TurnOnCommand turnOn(&light);
  TurnOffCommand turnOff(&light);

  RemoteControl remote;

  remote.setCommand(&turnOn);
  remote.pressButton(); // The light is ON.

  remote.setCommand(&turnOff);
  remote.pressButton(); // The light is OFF.

  return 0;
}
