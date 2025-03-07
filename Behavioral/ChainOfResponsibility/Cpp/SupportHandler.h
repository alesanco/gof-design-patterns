// SupportHandler.h

#ifndef SUPPORT_HANDLER_H
#define SUPPORT_HANDLER_H

#include <string>

class SupportHandler {
protected:
  SupportHandler* nextHandler;

public:
  SupportHandler() : nextHandler(nullptr) {}
  void setNextHandler(SupportHandler* handler) { nextHandler = handler; }
  virtual void handleRequest(const std::string& request) = 0;
  virtual ~SupportHandler() = default;
};

#endif // SUPPORT_HANDLER_H
