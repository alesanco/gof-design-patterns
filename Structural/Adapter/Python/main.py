# main.py
from mp3_player import MP3Player

if __name__ == "__main__":
  player = MP3Player()

  player.play("MP3", "song.mp3")
  player.play("MP4", "video.mp4")
  player.play("VLC", "movie.vlc")
  player.play("AVI", "unsupported.avi")
