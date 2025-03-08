// History.cs

using System.Collections.Generic;

public class History {
  private Stack<EditorMemento> history = new Stack<EditorMemento>();

  public void Save(EditorMemento memento) {
    if (memento != null) {
      history.Push(memento);
    }
  }

  public EditorMemento? Undo() {
    if (history.Count > 1) {
      history.Pop(); // Remove the latest state
    }
    return history.Count > 0 ? history.Peek() : null; // Return the previous state
  }
}
