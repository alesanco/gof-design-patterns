// User.cs

public abstract class User {
  protected IMediator mediator;
  protected string name;

  public User(IMediator mediator, string name) {
    this.mediator = mediator;
    this.name = name;
  }

  public abstract void SendMessage(string message);
  public abstract void ReceiveMessage(string message);
}
