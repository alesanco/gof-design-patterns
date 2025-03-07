// TurnOffCommand.h

#ifndef TURN_OFF_COMMAND_H
#define TURN_OFF_COMMAND_H

#include "Command.h"
#include "Light.h"

class TurnOffCommand : public Command {
private:
  Light* light;

public:
  TurnOffCommand(Light* light) : light(light) {}
  void execute() override { light->turnOff(); }
};

#endif // TURN_OFF_COMMAND_H
