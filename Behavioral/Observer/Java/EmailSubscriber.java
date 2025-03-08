// EmailSubscriber.java

public class EmailSubscriber extends Subscriber {
  public EmailSubscriber(String name) {
    super(name);
  }

  @Override
  public void update(String news) {
    System.out.println(getName() + " (Email) received: " + news);
  }
}
