// Manager.cpp

#include "Manager.h"

void Manager::handleRequest(const std::string& request) {
  if (request == "Advanced Issue") {
    std::cout << "Manager: Handling request - " << request << std::endl;
  } else {
    std::cout << "No handler available for - " << request << std::endl;
  }
}
