# advanced_remote.py

from basic_remote import BasicRemote

class AdvancedRemote(BasicRemote):
  def mute(self):
    self.device.set_volume(0)
    print("Device is muted.")
