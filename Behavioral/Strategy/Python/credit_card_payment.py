# credit_card_payment.py

from payment_strategy import PaymentStrategy

class CreditCardPayment(PaymentStrategy):
  def __init__(self, card_number):
    self.card_number = card_number

  def pay(self, amount):
    print(f"Paid ${amount} using Credit Card (Card Number: {self.card_number})")
