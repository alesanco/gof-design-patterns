// NewsAgency.cs

using System;
using System.Collections.Generic;

public class NewsAgency : ISubject {
  private List<IObserver> observers = new List<IObserver>();

  public void AddObserver(IObserver observer) {
    observers.Add(observer);
  }

  public void RemoveObserver(IObserver observer) {
    observers.Remove(observer);
  }

  public void NotifyObservers(string news) {
    foreach (IObserver observer in observers) {
      observer.Update(news);
    }
  }
}
