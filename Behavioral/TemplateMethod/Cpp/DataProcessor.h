// DataProcessor.h

#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <iostream>

class DataProcessor {
public:
  // Template method defining the structure of the algorithm
  void process();

  // Abstract method to be implemented by subclasses
  virtual void readData() = 0;

  // Concrete method with common behavior
  virtual void processData();
  
  // Concrete method with common behavior
  virtual void saveData();

  virtual ~DataProcessor() = default;
};

#endif // DATAPROCESSOR_H
