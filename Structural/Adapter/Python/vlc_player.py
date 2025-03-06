# vlc_player.py
from advanced_media_player import AdvancedMediaPlayer

class VLCPlayer(AdvancedMediaPlayer):
  def play_mp4(self, file_name: str):
    pass  # VLCPlayer does not support MP4

  def play_vlc(self, file_name: str):
    print(f"Playing VLC file: {file_name}")
