# mp3_player.py
from media_player import MediaPlayer
from media_adapter import MediaAdapter

class MP3Player(MediaPlayer):
  def play(self, audio_type: str, file_name: str):
    if audio_type.lower() == "mp3":
      print(f"Playing MP3 file: {file_name}")
    elif audio_type.lower() in ["mp4", "vlc"]:
      adapter = MediaAdapter(audio_type)
      adapter.play(audio_type, file_name)
    else:
      print(f"Invalid media type: {audio_type}")
