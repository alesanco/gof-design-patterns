// Program.cs

using System;

class Program {
  static void Main() {
    TextEditor editor = new TextEditor();
    
    string text = "Hello Flyweight!";
    foreach (char c in text) {
      editor.AddCharacter(c);
    }

    editor.DisplayCharacters();
  }
}
