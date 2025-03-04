#ifndef CREATOR_H
#define CREATOR_H

#include "Product.h"

class Creator {
public:
  virtual Product* createProduct() = 0;
  virtual ~Creator() = default;
};

#endif // CREATOR_H
