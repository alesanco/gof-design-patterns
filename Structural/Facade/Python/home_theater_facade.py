# home_theater_facade.py

from dvd_player import DVDPlayer
from projector import Projector
from sound_system import SoundSystem
from screen import Screen

class HomeTheaterFacade:
  def __init__(self, dvd_player, projector, sound_system, screen):
    self.dvd_player = dvd_player
    self.projector = projector
    self.sound_system = sound_system
    self.screen = screen

  def watch_movie(self, movie):
    print("\nGetting ready to watch a movie...")
    self.screen.lower()
    self.projector.turn_on()
    self.projector.set_input("DVD")
    self.sound_system.turn_on()
    self.sound_system.set_volume(10)
    self.dvd_player.turn_on()
    self.dvd_player.play(movie)

  def end_movie(self):
    print("\nShutting down home theater...")
    self.dvd_player.turn_off()
    self.sound_system.turn_off()
    self.projector.turn_off()
    self.screen.raise_screen()
