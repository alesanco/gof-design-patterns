# main.py

from dvd_player import DVDPlayer
from projector import Projector
from sound_system import SoundSystem
from screen import Screen
from home_theater_facade import HomeTheaterFacade

if __name__ == "__main__":
  dvd_player = DVDPlayer()
  projector = Projector()
  sound_system = SoundSystem()
  screen = Screen()

  home_theater = HomeTheaterFacade(dvd_player, projector, sound_system, screen)

  home_theater.watch_movie("Inception")
  home_theater.end_movie()
