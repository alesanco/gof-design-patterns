// paymentProcessor.js

class PaymentProcessor {
  constructor() {
    this.paymentStrategy = null;
  }

  setPaymentStrategy(paymentStrategy) {
    this.paymentStrategy = paymentStrategy;
  }

  processPayment(amount) {
    if (!this.paymentStrategy) {
      console.log("No payment strategy selected.");
      return;
    }
    this.paymentStrategy.pay(amount);
  }
}

module.exports = PaymentProcessor;
