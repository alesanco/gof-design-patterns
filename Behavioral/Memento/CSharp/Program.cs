// Program.cs

using System;

class Program {
  static void Main() {
    Editor editor = new Editor();
    History history = new History();

    // Always save the initial empty state
    history.Save(editor.Save());

    // Save before making any changes
    editor.Type("Hello, World!");
    history.Save(editor.Save());

    editor.Type("New content added.");
    history.Save(editor.Save());

    Console.WriteLine("Current content: " + editor.GetContent());

    editor.Restore(history.Undo());
    Console.WriteLine("After undo: " + editor.GetContent());

    editor.Restore(history.Undo());
    Console.WriteLine("After second undo: " + editor.GetContent());
  }
}
