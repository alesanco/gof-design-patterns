// Supervisor.cpp

#include "Supervisor.h"

void Supervisor::handleRequest(const std::string& request) {
  if (request == "Intermediate Issue") {
    std::cout << "Supervisor: Handling request - " << request << std::endl;
  } else if (nextHandler) {
    nextHandler->handleRequest(request);
  } else {
    std::cout << "No handler available for - " << request << std::endl;
  }
}
