// File.cpp

#include "File.h"

File::File(const std::string& name) : name(name) {}

void File::showDetails() const {
  std::cout << "File: " << name << std::endl;
}
