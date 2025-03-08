// History.h

#ifndef HISTORY_H
#define HISTORY_H

#include "EditorMemento.h"
#include <stack>

class History {
private:
  std::stack<EditorMemento> history;

public:
  void save(const EditorMemento& memento);
  EditorMemento undo();
};

#endif // HISTORY_H
