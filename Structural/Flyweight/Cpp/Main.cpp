// Main.cpp

#include "TextEditor.h"

int main() {
  TextEditor editor;
  
  std::string text = "Hello Flyweight!";
  for (char c : text) {
    editor.addCharacter(c);
  }

  editor.displayCharacters();

  // Cleanup to prevent memory leaks
  CharacterFactory::cleanup();

  return 0;
}
