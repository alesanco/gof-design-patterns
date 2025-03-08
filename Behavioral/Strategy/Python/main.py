# main.py

from payment_processor import PaymentProcessor
from credit_card_payment import CreditCardPayment
from paypal_payment import PayPalPayment
from bitcoin_payment import BitcoinPayment

if __name__ == "__main__":
  processor = PaymentProcessor()

  processor.set_payment_strategy(CreditCardPayment("1234-5678-9876-5432"))
  processor.process_payment(100.0)

  processor.set_payment_strategy(PayPalPayment("user@example.com"))
  processor.process_payment(50.0)

  processor.set_payment_strategy(BitcoinPayment("1A2b3C4d5E6f7G8h9I"))
  processor.process_payment(200.0)
