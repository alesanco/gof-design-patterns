# support_handler.py

from abc import ABC, abstractmethod

class SupportHandler(ABC):
  def __init__(self):
    self._next_handler = None

  def set_next_handler(self, handler):
    self._next_handler = handler

  @abstractmethod
  def handle_request(self, request):
    pass
