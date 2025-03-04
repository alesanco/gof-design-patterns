#ifndef CONCRETE_CREATOR_B_H
#define CONCRETE_CREATOR_B_H

#include "Creator.h"

class ConcreteCreatorB : public Creator {
public:
  Product* createProduct() override;
};

#endif // CONCREATOR_B_H
