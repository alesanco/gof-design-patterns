// Editor.h

#ifndef EDITOR_H
#define EDITOR_H

#include "EditorMemento.h"
#include <string>

class Editor {
private:
  std::string content;

public:
  void type(const std::string& words);
  EditorMemento save() const;
  void restore(const EditorMemento& memento);
  std::string getContent() const;
};

#endif // EDITOR_H
