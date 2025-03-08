// CSVProcessor.h

#ifndef CSVPROCESSOR_H
#define CSVPROCESSOR_H

#include "DataProcessor.h"

class CSVProcessor : public DataProcessor {
public:
  void readData() override;
};

#endif // CSVPROCESSOR_H
