// Supervisor.h

#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "SupportHandler.h"
#include <iostream>

class Supervisor : public SupportHandler {
public:
  void handleRequest(const std::string& request) override;
};

#endif // SUPERVISOR_H
