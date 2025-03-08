// DataProcessor.cpp

#include "DataProcessor.h"

void DataProcessor::process() {
  readData();
  processData();
  saveData();
}

void DataProcessor::processData() {
  std::cout << "Processing data..." << std::endl;
}

void DataProcessor::saveData() {
  std::cout << "Data saved successfully." << std::endl;
}
