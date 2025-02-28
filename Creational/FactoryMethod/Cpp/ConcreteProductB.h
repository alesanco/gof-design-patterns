#ifndef CONCRETE_PRODUCT_B_H
#define CONCRETE_PRODUCT_B_H

#include "Product.h"
#include <iostream>

class ConcreteProductB : public Product {
public:
  void use() override {
    std::cout << "Using Product B" << std::endl;
  }
};

#endif // CONCRETE_PRODUCT_B_H
