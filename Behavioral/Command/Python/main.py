# main.py

from light import Light
from turn_on_command import TurnOnCommand
from turn_off_command import TurnOffCommand
from remote_control import RemoteControl

if __name__ == "__main__":
  light = Light()
  turn_on = TurnOnCommand(light)
  turn_off = TurnOffCommand(light)

  remote = RemoteControl()

  remote.set_command(turn_on)
  remote.press_button()  # The light is ON.

  remote.set_command(turn_off)
  remote.press_button()  # The light is OFF.
