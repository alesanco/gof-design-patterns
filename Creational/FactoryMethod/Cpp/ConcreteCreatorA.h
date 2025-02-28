#ifndef CONCRETE_CREATOR_A_H
#define CONCRETE_CREATOR_A_H

#include "Creator.h"
#include "ConcreteProductA.h"

class ConcreteCreatorA : public Creator {
public:
  Product* createProduct() override {
    return new ConcreteProductA();
  }
};

#endif // CONCRETE_CREATOR_A_H
