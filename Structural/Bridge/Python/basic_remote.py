# basic_remote.py

from remote import Remote

class BasicRemote(Remote):
  def volume_up(self):
    self.device.set_volume(self.device.get_volume() + 10)
  def volume_down(self):
    self.device.set_volume(self.device.get_volume() - 10)
