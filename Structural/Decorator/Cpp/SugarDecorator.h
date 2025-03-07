// SugarDecorator.h

#ifndef SUGARDECORATOR_H
#define SUGARDECORATOR_H

#include "CoffeeDecorator.h"

class SugarDecorator : public CoffeeDecorator {
public:
  SugarDecorator(std::unique_ptr<ICoffee> coffee);
  std::string getDescription() const override;
  double getCost() const override;
};

#endif // SUGARDECORATOR_H
