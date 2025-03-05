// ConcreteCreatorB.cpp
#include "ConcreteCreatorB.h"
#include "ConcreteProductB.h"

Product* ConcreteCreatorB::createProduct() {
  return new ConcreteProductB();
}
