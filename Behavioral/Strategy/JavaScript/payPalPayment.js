// payPalPayment.js

const PaymentStrategy = require("./paymentStrategy");

class PayPalPayment extends PaymentStrategy {
  constructor(email) {
    super();
    this.email = email;
  }

  pay(amount) {
    console.log(`Paid $${amount} using PayPal (Email: ${this.email})`);
  }
}

module.exports = PayPalPayment;
