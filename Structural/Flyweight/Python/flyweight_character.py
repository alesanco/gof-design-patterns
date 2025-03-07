# flyweight_character.py

class FlyweightCharacter:
  def __init__(self, symbol: str):
    self._symbol = symbol

  def display(self):
    print(f"Character: {self._symbol}")
