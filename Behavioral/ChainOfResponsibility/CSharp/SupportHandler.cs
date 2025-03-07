// SupportHandler.cs

public abstract class SupportHandler {
  protected SupportHandler? NextHandler;

  public void SetNextHandler(SupportHandler nextHandler) {
    NextHandler = nextHandler;
  }

  public abstract void HandleRequest(string request);
}
