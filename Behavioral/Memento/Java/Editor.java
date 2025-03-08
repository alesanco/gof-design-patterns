// Editor.java

public class Editor {
  private String content = "";

  public void type(String words) {
    content = words;
  }

  public EditorMemento save() {
    return new EditorMemento(content);
  }

  public void restore(EditorMemento memento) {
    if (memento != null) {
      content = memento.getContent();
    }
  }

  public String getContent() {
    return content;
  }
}
