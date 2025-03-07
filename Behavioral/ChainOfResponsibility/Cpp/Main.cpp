// Main.cpp

#include "BasicSupport.h"
#include "Supervisor.h"
#include "Manager.h"

int main() {
  BasicSupport basic;
  Supervisor supervisor;
  Manager manager;

  // Setting up the chain
  basic.setNextHandler(&supervisor);
  supervisor.setNextHandler(&manager);

  // Sending requests
  basic.handleRequest("Basic Issue");
  basic.handleRequest("Intermediate Issue");
  basic.handleRequest("Advanced Issue");
  basic.handleRequest("Unknown Issue");

  return 0;
}
