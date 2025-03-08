// SMSSubscriber.java

public class SMSSubscriber extends Subscriber {
  public SMSSubscriber(String name) {
    super(name);
  }

  @Override
  public void update(String news) {
    System.out.println(getName() + " (SMS) received: " + news);
  }
}
