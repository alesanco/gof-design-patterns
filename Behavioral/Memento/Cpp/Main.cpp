// Main.cpp

#include "Editor.h"
#include "History.h"
#include <iostream>

int main() {
  Editor editor;
  History history;

  // Always save the initial empty state
  history.save(editor.save());

  // Save before making any changes
  editor.type("Hello, World!");
  history.save(editor.save());

  editor.type("New content added.");
  history.save(editor.save());

  std::cout << "Current content: " << editor.getContent() << std::endl;

  editor.restore(history.undo());
  std::cout << "After undo: " << editor.getContent() << std::endl;

  editor.restore(history.undo());
  std::cout << "After second undo: " << editor.getContent() << std::endl;

  return 0;
}
