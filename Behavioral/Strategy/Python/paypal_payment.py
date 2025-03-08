# paypal_payment.py

from payment_strategy import PaymentStrategy

class PayPalPayment(PaymentStrategy):
  def __init__(self, email):
    self.email = email

  def pay(self, amount):
    print(f"Paid ${amount} using PayPal (Email: {self.email})")
