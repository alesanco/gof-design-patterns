# file_system_component.py

from abc import ABC, abstractmethod

class FileSystemComponent(ABC):
  
  @abstractmethod
  def show_details(self):
    pass
