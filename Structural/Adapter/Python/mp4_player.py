# mp4_player.py
from advanced_media_player import AdvancedMediaPlayer

class MP4Player(AdvancedMediaPlayer):
  def play_mp4(self, file_name: str):
    print(f"Playing MP4 file: {file_name}")

  def play_vlc(self, file_name: str):
    pass  # MP4Player does not support VLC
