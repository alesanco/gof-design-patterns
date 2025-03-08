// bitcoinPayment.js

const PaymentStrategy = require("./paymentStrategy");

class BitcoinPayment extends PaymentStrategy {
  constructor(walletAddress) {
    super();
    this.walletAddress = walletAddress;
  }

  pay(amount) {
    console.log(`Paid $${amount} using Bitcoin (Wallet: ${this.walletAddress})`);
  }
}

module.exports = BitcoinPayment;
