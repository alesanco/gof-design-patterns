// PaymentProcessor.cpp

#include "PaymentProcessor.h"
#include <iostream>

PaymentProcessor::PaymentProcessor() : paymentStrategy(nullptr) {}

PaymentProcessor::~PaymentProcessor() {
  delete paymentStrategy;
}

void PaymentProcessor::setPaymentStrategy(PaymentStrategy* strategy) {
  delete paymentStrategy;
  paymentStrategy = strategy;
}

void PaymentProcessor::processPayment(double amount) {
  if (paymentStrategy == nullptr) {
    std::cout << "No payment strategy selected." << std::endl;
    return;
  }
  paymentStrategy->pay(amount);
}
