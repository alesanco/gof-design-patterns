# main.py

from text_editor import TextEditor

if __name__ == "__main__":
  editor = TextEditor()
  
  text = "Hello Flyweight!"
  for char in text:
    editor.add_character(char)

  editor.display_characters()
