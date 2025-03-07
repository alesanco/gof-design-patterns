// TextEditor.h

#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include "CharacterFactory.h"
#include <vector>

class TextEditor {
private:
  std::vector<FlyweightCharacter*> characters;

public:
  void addCharacter(char symbol);
  void displayCharacters() const;
};

#endif // TEXT_EDITOR_H
