// Subscriber.java

public class Subscriber implements Observer {
  private String name;

  public Subscriber(String name) {
    this.name = name;
  }

  protected String getName() {
    return name;
  }

  @Override
  public void update(String news) {
    System.out.println(name + " received news update: " + news);
  }
}
