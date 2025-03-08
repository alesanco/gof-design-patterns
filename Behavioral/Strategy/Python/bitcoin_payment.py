# bitcoin_payment.py

from payment_strategy import PaymentStrategy

class BitcoinPayment(PaymentStrategy):
  def __init__(self, wallet_address):
    self.wallet_address = wallet_address

  def pay(self, amount):
    print(f"Paid ${amount} using Bitcoin (Wallet: {self.wallet_address})")
