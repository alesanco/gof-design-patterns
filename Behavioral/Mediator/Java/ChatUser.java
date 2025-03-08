// ChatUser.java

public class ChatUser extends User {
  public ChatUser(Mediator mediator, String name) {
    super(mediator, name);
  }

  @Override
  public void sendMessage(String message) {
    System.out.println(name + " sends: " + message);
    mediator.sendMessage(message, this);
  }

  @Override
  public void receiveMessage(String message) {
    System.out.println(name + " receives: " + message);
  }
}
