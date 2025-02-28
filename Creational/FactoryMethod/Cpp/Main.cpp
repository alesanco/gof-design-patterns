#include <iostream>
#include "ConcreteCreatorA.h"
#include "ConcreteCreatorB.h"

int main() {
  Creator* creatorA = new ConcreteCreatorA();
  Product* productA = creatorA->createProduct();
  productA->use();
  
  Creator* creatorB = new ConcreteCreatorB();
  Product* productB = creatorB->createProduct();
  productB->use();

  // Clean up memory
  delete productA;
  delete productB;
  delete creatorA;
  delete creatorB;

  return 0;
}
