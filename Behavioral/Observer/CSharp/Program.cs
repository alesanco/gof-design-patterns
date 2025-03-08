// Program.cs

using System;

class Program {
  static void Main() {
    NewsAgency agency = new NewsAgency();

    IObserver subscriber1 = new EmailSubscriber("Alice");
    IObserver subscriber2 = new SMSSubscriber("Bob");
    IObserver subscriber3 = new EmailSubscriber("Charlie");

    agency.AddObserver(subscriber1);
    agency.AddObserver(subscriber2);
    agency.AddObserver(subscriber3);

    agency.NotifyObservers("Breaking News: Observer Pattern Implemented!");

    agency.RemoveObserver(subscriber2);

    agency.NotifyObservers("Update: C# Observer Example Completed!");
  }
}
