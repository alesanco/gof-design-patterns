# tv.py

from device import Device

class TV(Device):
  def __init__(self):
    self._on = False
    self._volume = 50

  def turn_on(self):
    self._on = True
    print("TV is now ON.")

  def turn_off(self):
    self._on = False
    print("TV is now OFF.")

  def set_volume(self, volume: int):
    self._volume = volume
    print(f"TV volume set to {volume}")

  def get_volume(self) -> int:
    return self._volume

  def is_on(self) -> bool:
    return self._on
