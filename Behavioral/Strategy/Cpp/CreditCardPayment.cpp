// CreditCardPayment.cpp

#include "CreditCardPayment.h"

CreditCardPayment::CreditCardPayment(const std::string& cardNumber) : cardNumber(cardNumber) {}

void CreditCardPayment::pay(double amount) {
  std::cout << "Paid $" << amount << " using Credit Card (Card Number: " << cardNumber << ")" << std::endl;
}
