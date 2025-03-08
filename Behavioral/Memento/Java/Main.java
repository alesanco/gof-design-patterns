// Main.java

public class Main {
  public static void main(String[] args) {
    Editor editor = new Editor();
    History history = new History();

    // Always save the initial empty state
    history.save(editor.save());

    // Save before making any changes
    editor.type("Hello, World!");
    history.save(editor.save());

    editor.type("New content added.");
    history.save(editor.save());

    System.out.println("Current content: " + editor.getContent());

    editor.restore(history.undo());
    System.out.println("After undo: " + editor.getContent());

    editor.restore(history.undo());
    System.out.println("After second undo: " + editor.getContent());
  }
}
