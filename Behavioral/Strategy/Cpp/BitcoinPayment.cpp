// BitcoinPayment.cpp

#include "BitcoinPayment.h"

BitcoinPayment::BitcoinPayment(const std::string& walletAddress) : walletAddress(walletAddress) {}

void BitcoinPayment::pay(double amount) {
  std::cout << "Paid $" << amount << " using Bitcoin (Wallet: " << walletAddress << ")" << std::endl;
}
