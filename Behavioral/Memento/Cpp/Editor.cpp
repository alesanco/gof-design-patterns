// Editor.cpp

#include "Editor.h"

void Editor::type(const std::string& words) {
  content = words;
}

EditorMemento Editor::save() const {
  return EditorMemento(content);
}

void Editor::restore(const EditorMemento& memento) {
  content = memento.getContent();
}

std::string Editor::getContent() const {
  return content;
}
