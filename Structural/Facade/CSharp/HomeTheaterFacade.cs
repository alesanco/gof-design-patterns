// HomeTheaterFacade.cs

using System;

public class HomeTheaterFacade {
  private DVDPlayer dvdPlayer;
  private Projector projector;
  private SoundSystem soundSystem;
  private Screen screen;

  public HomeTheaterFacade(DVDPlayer dvdPlayer, Projector projector, SoundSystem soundSystem, Screen screen) {
    this.dvdPlayer = dvdPlayer;
    this.projector = projector;
    this.soundSystem = soundSystem;
    this.screen = screen;
  }

  public void WatchMovie(string movie) {
    Console.WriteLine("\nGetting ready to watch a movie...");
    screen.Lower();
    projector.TurnOn();
    projector.SetInput("DVD");
    soundSystem.TurnOn();
    soundSystem.SetVolume(10);
    dvdPlayer.TurnOn();
    dvdPlayer.Play(movie);
  }

  public void EndMovie() {
    Console.WriteLine("\nShutting down home theater...");
    dvdPlayer.TurnOff();
    soundSystem.TurnOff();
    projector.TurnOff();
    screen.Raise();
  }
}
