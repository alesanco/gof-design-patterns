// BasicSupport.h

#ifndef BASIC_SUPPORT_H
#define BASIC_SUPPORT_H

#include "SupportHandler.h"
#include <iostream>

class BasicSupport : public SupportHandler {
public:
  void handleRequest(const std::string& request) override;
};

#endif // BASIC_SUPPORT_H
