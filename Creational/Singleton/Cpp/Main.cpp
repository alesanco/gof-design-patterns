// Main.cpp

#include "Logger.h"

int main() {
  Logger* logger1 = Logger::getInstance();
  logger1->log("Initializing the system...");

  Logger* logger2 = Logger::getInstance();
  logger2->log("System running.");

  // Verify if both instances are the same
  std::cout << "Logger instances are the same: " << (logger1 == logger2) << std::endl;

  return 0;
}
