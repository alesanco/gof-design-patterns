# history.py

class History:
  def __init__(self):
    self._history = []

  def save(self, memento):
    if memento:
      self._history.append(memento)

  def undo(self):
    if len(self._history) > 1:
      self._history.pop()  # Remove the latest state
    return self._history[-1] if self._history else None
