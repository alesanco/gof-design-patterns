# media_adapter.py
from media_player import MediaPlayer
from mp4_player import MP4Player
from vlc_player import VLCPlayer

class MediaAdapter(MediaPlayer):
  def __init__(self, audio_type: str):
    if audio_type.lower() == "mp4":
      self.advanced_media_player = MP4Player()
    elif audio_type.lower() == "vlc":
      self.advanced_media_player = VLCPlayer()
    else:
      self.advanced_media_player = None

  def play(self, audio_type: str, file_name: str):
    if self.advanced_media_player:
      if audio_type.lower() == "mp4":
        self.advanced_media_player.play_mp4(file_name)
      elif audio_type.lower() == "vlc":
        self.advanced_media_player.play_vlc(file_name)
