// IIterator.cs

public interface IIterator<T> {
  bool HasNext();
  T? Next();
}
