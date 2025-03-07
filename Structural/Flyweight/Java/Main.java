// Main.java

public class Main {
  public static void main(String[] args) {
    TextEditor editor = new TextEditor();
    
    String text = "Hello Flyweight!";
    for (char c : text.toCharArray()) {
      editor.addCharacter(c);
    }

    editor.displayCharacters();
  }
}
