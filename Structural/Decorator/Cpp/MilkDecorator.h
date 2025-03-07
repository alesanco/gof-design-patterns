// MilkDecorator.h

#ifndef MILKDECORATOR_H
#define MILKDECORATOR_H

#include "CoffeeDecorator.h"

class MilkDecorator : public CoffeeDecorator {
public:
  MilkDecorator(std::unique_ptr<ICoffee> coffee);
  std::string getDescription() const override;
  double getCost() const override;
};

#endif // MILKDECORATOR_H
