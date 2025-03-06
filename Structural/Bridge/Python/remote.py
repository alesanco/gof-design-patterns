# remote.py

from abc import ABC, abstractmethod
from device import Device

class Remote(ABC):
  def __init__(self, device: Device):
    self.device = device

  def toggle_power(self):
    if self.device.is_on():
      self.device.turn_off()
    else:
      self.device.turn_on()

  @abstractmethod
  def volume_up(self):
    pass

  @abstractmethod
  def volume_down(self):
    pass
