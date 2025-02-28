#ifndef CONCRETE_CREATOR_B_H
#define CONCRETE_CREATOR_B_H

#include "Creator.h"
#include "ConcreteProductB.h"

class ConcreteCreatorB : public Creator {
public:
  Product* createProduct() override {
    return new ConcreteProductB();
  }
};

#endif // CONCREATOR_B_H
