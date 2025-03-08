// JSONProcessor.h

#ifndef JSONPROCESSOR_H
#define JSONPROCESSOR_H

#include "DataProcessor.h"

class JSONProcessor : public DataProcessor {
public:
  void readData() override;
};

#endif // JSONPROCESSOR_H
