// Manager.h

#ifndef MANAGER_H
#define MANAGER_H

#include "SupportHandler.h"
#include <iostream>

class Manager : public SupportHandler {
public:
  void handleRequest(const std::string& request) override;
};

#endif // MANAGER_H
