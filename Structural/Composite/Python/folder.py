# folder.py

from file_system_component import FileSystemComponent

class Folder(FileSystemComponent):
  
  def __init__(self, name):
    self.name = name
    self.components = []

  def add_component(self, component):
    self.components.append(component)

  def show_details(self):
    print(f"Folder: {self.name}")
    for component in self.components:
      component.show_details()
