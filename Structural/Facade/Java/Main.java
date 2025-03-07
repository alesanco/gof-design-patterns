// Main.java

public class Main {
  public static void main(String[] args) {
    DVDPlayer dvdPlayer = new DVDPlayer();
    Projector projector = new Projector();
    SoundSystem soundSystem = new SoundSystem();
    Screen screen = new Screen();

    HomeTheaterFacade homeTheater = new HomeTheaterFacade(dvdPlayer, projector, soundSystem, screen);

    homeTheater.watchMovie("Inception");
    homeTheater.endMovie();
  }
}
