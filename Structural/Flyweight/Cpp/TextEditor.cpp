// TextEditor.cpp

#include "TextEditor.h"
#include <iostream>

void TextEditor::addCharacter(char symbol) {
  characters.push_back(CharacterFactory::getCharacter(symbol));
}

void TextEditor::displayCharacters() const {
  for (FlyweightCharacter* character : characters) {
    character->display();
  }
  std::cout << "Total unique characters in memory: " << CharacterFactory::getPoolSize() << std::endl;
}
