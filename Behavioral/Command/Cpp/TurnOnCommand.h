// TurnOnCommand.h

#ifndef TURN_ON_COMMAND_H
#define TURN_ON_COMMAND_H

#include "Command.h"
#include "Light.h"

class TurnOnCommand : public Command {
private:
  Light* light;

public:
  TurnOnCommand(Light* light) : light(light) {}
  void execute() override { light->turnOn(); }
};

#endif // TURN_ON_COMMAND_H
