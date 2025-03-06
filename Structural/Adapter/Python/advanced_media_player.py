# advanced_media_player.py
from abc import ABC, abstractmethod

class AdvancedMediaPlayer(ABC):
  @abstractmethod
  def play_mp4(self, file_name: str):
    pass

  @abstractmethod
  def play_vlc(self, file_name: str):
    pass
