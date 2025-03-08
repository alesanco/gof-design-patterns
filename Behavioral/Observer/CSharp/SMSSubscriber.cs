// SMSSubscriber.cs

using System;

public class SMSSubscriber : Subscriber {
  public SMSSubscriber(string name) : base(name) {}

  public override void Update(string news) {
    Console.WriteLine($"{Name} (SMS) received: {news}");
  }
}
