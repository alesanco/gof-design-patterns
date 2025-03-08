# main.py

from editor import Editor
from history import History

if __name__ == "__main__":
  editor = Editor()
  history = History()

  # Always save the initial empty state
  history.save(editor.save())

  # Save before making any changes
  editor.type("Hello, World!")
  history.save(editor.save())

  editor.type("New content added.")
  history.save(editor.save())

  print("Current content:", editor.get_content())

  editor.restore(history.undo())
  print("After undo:", editor.get_content())

  editor.restore(history.undo())
  print("After second undo:", editor.get_content())
