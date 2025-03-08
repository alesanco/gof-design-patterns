// BitcoinPayment.h

#ifndef BITCOINPAYMENT_H
#define BITCOINPAYMENT_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

class BitcoinPayment : public PaymentStrategy {
private:
  std::string walletAddress;

public:
  explicit BitcoinPayment(const std::string& walletAddress);
  void pay(double amount) override;
};

#endif // BITCOINPAYMENT_H
