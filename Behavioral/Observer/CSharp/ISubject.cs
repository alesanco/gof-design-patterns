// ISubject.cs

public interface ISubject {
  void AddObserver(IObserver observer);
  void RemoveObserver(IObserver observer);
  void NotifyObservers(string news);
}
