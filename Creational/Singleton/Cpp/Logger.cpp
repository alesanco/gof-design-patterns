// Logger.cpp

#include "Logger.h"

std::unique_ptr<Logger> Logger::instance;
std::mutex Logger::mutex;

Logger::Logger() {
  std::cout << "Logger instance created." << std::endl;
}

Logger* Logger::getInstance() {
  std::lock_guard<std::mutex> lock(mutex);
  if (!instance) {
    instance = std::unique_ptr<Logger>(new Logger());
  }
  return instance.get();
}

void Logger::log(const std::string& message) {
  std::cout << "[LOG]: " << message << std::endl;
}
