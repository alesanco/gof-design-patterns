// SimpleCoffee.h

#ifndef SIMPLECOFFEE_H
#define SIMPLECOFFEE_H

#include "ICoffee.h"

class SimpleCoffee : public ICoffee {
public:
  std::string getDescription() const override;
  double getCost() const override;
};

#endif // SIMPLECOFFEE_H
