// RemoteControl.cpp

#include "RemoteControl.h"
#include <iostream>

void RemoteControl::pressButton() {
  if (command) {
    command->execute();
  } else {
    std::cout << "No command assigned to button." << std::endl;
  }
}
