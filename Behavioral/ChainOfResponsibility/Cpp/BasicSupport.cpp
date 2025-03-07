// BasicSupport.cpp

#include "BasicSupport.h"

void BasicSupport::handleRequest(const std::string& request) {
  if (request == "Basic Issue") {
    std::cout << "BasicSupport: Handling request - " << request << std::endl;
  } else if (nextHandler) {
    nextHandler->handleRequest(request);
  } else {
    std::cout << "No handler available for - " << request << std::endl;
  }
}
