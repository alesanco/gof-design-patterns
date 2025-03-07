# character_factory.py

from flyweight_character import FlyweightCharacter

class CharacterFactory:
  _character_pool = {}

  @staticmethod
  def get_character(symbol: str):
    if symbol not in CharacterFactory._character_pool:
      CharacterFactory._character_pool[symbol] = FlyweightCharacter(symbol)
    return CharacterFactory._character_pool[symbol]

  @staticmethod
  def get_pool_size():
    return len(CharacterFactory._character_pool)
