// CreditCardPayment.h

#ifndef CREDITCARDPAYMENT_H
#define CREDITCARDPAYMENT_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

class CreditCardPayment : public PaymentStrategy {
private:
  std::string cardNumber;

public:
  explicit CreditCardPayment(const std::string& cardNumber);
  void pay(double amount) override;
};

#endif // CREDITCARDPAYMENT_H
