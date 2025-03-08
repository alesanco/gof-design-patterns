// ChatUser.cs

using System;

public class ChatUser : User {
  public ChatUser(IMediator mediator, string name) : base(mediator, name) {}

  public override void SendMessage(string message) {
    Console.WriteLine($"{name} sends: {message}");
    mediator.SendMessage(message, this);
  }

  public override void ReceiveMessage(string message) {
    Console.WriteLine($"{name} receives: {message}");
  }
}
