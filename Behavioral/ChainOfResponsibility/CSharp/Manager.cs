// Manager.cs

using System;

public class Manager : SupportHandler {
  public override void HandleRequest(string request) {
    if (request == "Advanced Issue") {
      Console.WriteLine($"Manager: Handling request - {request}");
    } else {
      Console.WriteLine($"No handler available for - {request}");
    }
  }
}
