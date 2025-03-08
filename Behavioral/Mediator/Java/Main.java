// Main.java

public class Main {
  public static void main(String[] args) {
    ChatMediator chatMediator = new ChatMediator();

    User user1 = new ChatUser(chatMediator, "Alice");
    User user2 = new ChatUser(chatMediator, "Bob");
    User user3 = new ChatUser(chatMediator, "Charlie");

    chatMediator.addUser(user1);
    chatMediator.addUser(user2);
    chatMediator.addUser(user3);

    user1.sendMessage("Hello, everyone!");
    user2.sendMessage("Hey Alice!");
  }
}
