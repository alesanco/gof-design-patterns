// Subscriber.cs

using System;

public class Subscriber : IObserver {
  protected string Name { get; }

  public Subscriber(string name) {
    Name = name;
  }

  public virtual void Update(string news) {
    Console.WriteLine($"{Name} received news update: {news}");
  }
}
