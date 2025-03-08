// Main.cpp

#include "PaymentProcessor.h"
#include "CreditCardPayment.h"
#include "PayPalPayment.h"
#include "BitcoinPayment.h"

int main() {
  PaymentProcessor processor;

  processor.setPaymentStrategy(new CreditCardPayment("1234-5678-9876-5432"));
  processor.processPayment(100.0);

  processor.setPaymentStrategy(new PayPalPayment("user@example.com"));
  processor.processPayment(50.0);

  processor.setPaymentStrategy(new BitcoinPayment("1A2b3C4d5E6f7G8h9I"));
  processor.processPayment(200.0);

  return 0;
}
