// CoffeeDecorator.h

#ifndef COFFEEDECORATOR_H
#define COFFEEDECORATOR_H

#include "ICoffee.h"
#include <memory>

class CoffeeDecorator : public ICoffee {
protected:
  std::unique_ptr<ICoffee> decoratedCoffee;

public:
  CoffeeDecorator(std::unique_ptr<ICoffee> coffee);
  std::string getDescription() const override;
  double getCost() const override;
};

#endif // COFFEEDECORATOR_H
