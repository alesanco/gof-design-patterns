# remote_control.py

class RemoteControl:
  def __init__(self):
    self.command = None

  def set_command(self, command):
    self.command = command

  def press_button(self):
    if self.command:
      self.command.execute()
    else:
      print("No command assigned to button.")
