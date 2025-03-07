// ICoffee.h

#ifndef ICOFFEE_H
#define ICOFFEE_H

#include <string>

class ICoffee {
public:
  virtual ~ICoffee() = default;
  virtual std::string getDescription() const = 0;
  virtual double getCost() const = 0;
};

#endif // ICOFFEE_H
