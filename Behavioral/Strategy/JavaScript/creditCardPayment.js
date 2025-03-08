// creditCardPayment.js

const PaymentStrategy = require("./paymentStrategy");

class CreditCardPayment extends PaymentStrategy {
  constructor(cardNumber) {
    super();
    this.cardNumber = cardNumber;
  }

  pay(amount) {
    console.log(`Paid $${amount} using Credit Card (Card Number: ${this.cardNumber})`);
  }
}

module.exports = CreditCardPayment;
