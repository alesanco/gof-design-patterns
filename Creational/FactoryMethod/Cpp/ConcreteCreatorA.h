// ConcreteCreatorA.h

#ifndef CONCRETE_CREATOR_A_H
#define CONCRETE_CREATOR_A_H

#include "Creator.h"

class ConcreteCreatorA : public Creator {
public:
  Product* createProduct() override;
};

#endif // CONCRETE_CREATOR_A_H
