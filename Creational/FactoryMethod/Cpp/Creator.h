#ifndef CREATOR_H
#define CREATOR_H

#include "Product.h"

class Creator {
public:
  virtual Product* createProduct() = 0; // Factory Method
  virtual ~Creator() {}                 // Virtual destructor
};

#endif // CREATOR_H
