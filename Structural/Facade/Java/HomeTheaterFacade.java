// HomeTheaterFacade.java

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

  public void watchMovie(String movie) {
    System.out.println("\nGetting ready to watch a movie...");
    screen.lower();
    projector.turnOn();
    projector.setInput("DVD");
    soundSystem.turnOn();
    soundSystem.setVolume(10);
    dvdPlayer.turnOn();
    dvdPlayer.play(movie);
  }

  public void endMovie() {
    System.out.println("\nShutting down home theater...");
    dvdPlayer.turnOff();
    soundSystem.turnOff();
    projector.turnOff();
    screen.raise();
  }
}
