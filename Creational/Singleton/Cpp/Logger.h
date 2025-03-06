// Logger.h

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <memory>
#include <mutex>

class Logger {
private:
  static std::unique_ptr<Logger> instance;
  static std::mutex mutex;

  Logger(); // Private constructor to prevent direct instantiation

public:
  static Logger* getInstance();
  void log(const std::string& message);

  // Delete copy constructor and assignment operator
  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;
};

#endif // LOGGER_H
