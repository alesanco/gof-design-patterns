// History.java

import java.util.Stack;

public class History {
  private Stack<EditorMemento> history = new Stack<>();

  public void save(EditorMemento memento) {
    if (memento != null) {
      history.push(memento);
    }
  }

  public EditorMemento undo() {
    if (history.size() > 1) {
      history.pop(); // Remove the latest state
    }
    return history.isEmpty() ? null : history.peek(); // Return the previous state
  }
}

