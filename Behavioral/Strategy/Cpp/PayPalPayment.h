// PayPalPayment.h

#ifndef PAYPALPAYMENT_H
#define PAYPALPAYMENT_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

class PayPalPayment : public PaymentStrategy {
private:
  std::string email;

public:
  explicit PayPalPayment(const std::string& email);
  void pay(double amount) override;
};

#endif // PAYPALPAYMENT_H
