# main.py

from tv import TV
from radio import Radio
from basic_remote import BasicRemote
from advanced_remote import AdvancedRemote

if __name__ == "__main__":
  tv = TV()
  basic_remote = BasicRemote(tv)

  basic_remote.toggle_power()
  basic_remote.volume_up()
  basic_remote.volume_down()

  radio = Radio()
  advanced_remote = AdvancedRemote(radio)

  advanced_remote.toggle_power()
  advanced_remote.volume_up()
  advanced_remote.mute()
