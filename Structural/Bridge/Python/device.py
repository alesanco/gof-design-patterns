# device.py

from abc import ABC, abstractmethod

class Device(ABC):
  @abstractmethod
  def turn_on(self):
    pass

  @abstractmethod
  def turn_off(self):
    pass

  @abstractmethod
  def set_volume(self, volume: int):
    pass

  @abstractmethod
  def get_volume(self) -> int:
    pass

  @abstractmethod
  def is_on(self) -> bool:
    pass
