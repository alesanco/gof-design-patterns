// Editor.cs

public class Editor {
  private string content = "";

  public void Type(string words) {
    content = words;
  }

  public EditorMemento Save() {
    return new EditorMemento(content);
  }

  public void Restore(EditorMemento? memento) {
    if (memento != null) {
      content = memento.Content;
    }
  }

  public string GetContent() {
    return content;
  }
}
