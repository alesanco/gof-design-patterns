// History.cpp

#include "History.h"

void History::save(const EditorMemento& memento) {
  history.push(memento);
}

EditorMemento History::undo() {
  if (history.size() > 1) {
    history.pop(); // Remove the latest state
  }
  return history.empty() ? EditorMemento("") : history.top(); // Return the previous state
}
