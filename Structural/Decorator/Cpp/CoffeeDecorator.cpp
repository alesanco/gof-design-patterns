// CoffeeDecorator.cpp

#include "CoffeeDecorator.h"

CoffeeDecorator::CoffeeDecorator(std::unique_ptr<ICoffee> coffee)
  : decoratedCoffee(std::move(coffee)) {}

std::string CoffeeDecorator::getDescription() const {
  return decoratedCoffee->getDescription();
}

double CoffeeDecorator::getCost() const {
  return decoratedCoffee->getCost();
}
