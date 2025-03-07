// SugarDecorator.cpp

#include "SugarDecorator.h"

SugarDecorator::SugarDecorator(std::unique_ptr<ICoffee> coffee)
  : CoffeeDecorator(std::move(coffee)) {}

std::string SugarDecorator::getDescription() const {
  return decoratedCoffee->getDescription() + ", Sugar";
}

double SugarDecorator::getCost() const {
  return decoratedCoffee->getCost() + 0.5;
}
