#ifndef CONCRETE_PRODUCT_A_H
#define CONCRETE_PRODUCT_A_H

#include "Product.h"
#include <iostream>

class ConcreteProductA : public Product {
public:
  void use() override {
    std::cout << "Using Product A" << std::endl;
  }
};

#endif // CONCRETE_PRODUCT_A_H
