// Program.cs

using System;

class Program {
  static void Main() {
    DVDPlayer dvdPlayer = new DVDPlayer();
    Projector projector = new Projector();
    SoundSystem soundSystem = new SoundSystem();
    Screen screen = new Screen();

    HomeTheaterFacade homeTheater = new HomeTheaterFacade(dvdPlayer, projector, soundSystem, screen);

    homeTheater.WatchMovie("Inception");
    homeTheater.EndMovie();
  }
}
