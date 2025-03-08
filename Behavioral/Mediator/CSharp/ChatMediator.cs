// ChatMediator.cs

using System;
using System.Collections.Generic;

public class ChatMediator : IMediator {
  private readonly List<User> _users = new List<User>();

  public void AddUser(User user) {
    _users.Add(user);
  }

  public void SendMessage(string message, User sender) {
    foreach (var user in _users) {
      if (user != sender) {
        user.ReceiveMessage(message);
      }
    }
  }
}
