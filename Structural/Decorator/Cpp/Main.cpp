// Main.cpp

#include "SimpleCoffee.h"
#include "MilkDecorator.h"
#include "SugarDecorator.h"
#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<ICoffee> basicCoffee = std::make_unique<SimpleCoffee>();
  std::cout << basicCoffee->getDescription() << " -> $" << basicCoffee->getCost() << std::endl;

  std::unique_ptr<ICoffee> milkCoffee = std::make_unique<MilkDecorator>(std::move(basicCoffee));
  std::cout << milkCoffee->getDescription() << " -> $" << milkCoffee->getCost() << std::endl;

  std::unique_ptr<ICoffee> sugarMilkCoffee = std::make_unique<SugarDecorator>(std::move(milkCoffee));
  std::cout << sugarMilkCoffee->getDescription() << " -> $" << sugarMilkCoffee->getCost() << std::endl;

  return 0;
}
