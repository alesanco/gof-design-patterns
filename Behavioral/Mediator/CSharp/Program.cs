// Program.cs

using System;

class Program {
  static void Main() {
    ChatMediator chatMediator = new ChatMediator();

    User user1 = new ChatUser(chatMediator, "Alice");
    User user2 = new ChatUser(chatMediator, "Bob");
    User user3 = new ChatUser(chatMediator, "Charlie");

    chatMediator.AddUser(user1);
    chatMediator.AddUser(user2);
    chatMediator.AddUser(user3);

    user1.SendMessage("Hello, everyone!");
    user2.SendMessage("Hey Alice!");
  }
}
