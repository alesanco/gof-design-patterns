// EmailSubscriber.cs

using System;

public class EmailSubscriber : Subscriber {
  public EmailSubscriber(string name) : base(name) {}

  public override void Update(string news) {
    Console.WriteLine($"{Name} (Email) received: {news}");
  }
}
