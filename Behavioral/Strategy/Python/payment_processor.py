# payment_processor.py

class PaymentProcessor:
  def __init__(self):
    self._payment_strategy = None

  def set_payment_strategy(self, payment_strategy):
    self._payment_strategy = payment_strategy

  def process_payment(self, amount):
    if self._payment_strategy is None:
      print("No payment strategy selected.")
      return
    self._payment_strategy.pay(amount)
