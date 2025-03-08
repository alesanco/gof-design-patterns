// PayPalPayment.cpp

#include "PayPalPayment.h"

PayPalPayment::PayPalPayment(const std::string& email) : email(email) {}

void PayPalPayment::pay(double amount) {
  std::cout << "Paid $" << amount << " using PayPal (Email: " << email << ")" << std::endl;
}
