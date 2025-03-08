// ChatMediator.java

import java.util.ArrayList;
import java.util.List;

public class ChatMediator implements Mediator {
  private List<User> users = new ArrayList<>();

  public void addUser(User user) {
    users.add(user);
  }

  @Override
  public void sendMessage(String message, User sender) {
    for (User user : users) {
      if (user != sender) {
        user.receiveMessage(message);
      }
    }
  }
}
