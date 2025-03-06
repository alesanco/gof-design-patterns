// ConcreteCreatorA.cpp

#include "ConcreteCreatorA.h"
#include "ConcreteProductA.h"

Product* ConcreteCreatorA::createProduct() {
  return new ConcreteProductA();
}
