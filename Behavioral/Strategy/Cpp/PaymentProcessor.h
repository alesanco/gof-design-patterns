// PaymentProcessor.h

#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H

#include "PaymentStrategy.h"

class PaymentProcessor {
private:
  PaymentStrategy* paymentStrategy;

public:
  PaymentProcessor();
  ~PaymentProcessor();
  void setPaymentStrategy(PaymentStrategy* strategy);
  void processPayment(double amount);
};

#endif // PAYMENTPROCESSOR_H
