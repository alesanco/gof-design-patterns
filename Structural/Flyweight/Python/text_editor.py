# text_editor.py

from character_factory import CharacterFactory
from flyweight_character import FlyweightCharacter

class TextEditor:
  def __init__(self):
    self._characters = []

  def add_character(self, symbol: str):
    self._characters.append(CharacterFactory.get_character(symbol))

  def display_characters(self):
    for character in self._characters:
      character.display()
    print(f"Total unique characters in memory: {CharacterFactory.get_pool_size()}")
