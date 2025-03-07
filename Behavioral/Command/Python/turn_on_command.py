# turn_on_command.py

from command import Command

class TurnOnCommand(Command):
  def __init__(self, light):
    self.light = light

  def execute(self):
    self.light.turn_on()
