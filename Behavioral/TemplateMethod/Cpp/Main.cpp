// Main.cpp

#include "CSVProcessor.h"
#include "JSONProcessor.h"

int main() {
  CSVProcessor csvProcessor;
  csvProcessor.process();

  std::cout << "---------------------" << std::endl;

  JSONProcessor jsonProcessor;
  jsonProcessor.process();

  return 0;
}
