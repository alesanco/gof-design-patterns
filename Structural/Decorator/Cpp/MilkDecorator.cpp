// MilkDecorator.cpp

#include "MilkDecorator.h"

MilkDecorator::MilkDecorator(std::unique_ptr<ICoffee> coffee)
  : CoffeeDecorator(std::move(coffee)) {}

std::string MilkDecorator::getDescription() const {
  return decoratedCoffee->getDescription() + ", Milk";
}

double MilkDecorator::getCost() const {
  return decoratedCoffee->getCost() + 1.5;
}
