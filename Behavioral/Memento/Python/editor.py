# editor.py

from editor_memento import EditorMemento

class Editor:
  def __init__(self):
    self._content = ""

  def type(self, words):
    self._content = words

  def save(self):
    return EditorMemento(self._content)

  def restore(self, memento):
    if memento:
      self._content = memento.get_content()

  def get_content(self):
    return self._content
