// RemoteControl.h

#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include "Command.h"

class RemoteControl {
private:
  Command* command;

public:
  void setCommand(Command* cmd) { command = cmd; }
  void pressButton();
};

#endif // REMOTE_CONTROL_H
