// Supervisor.cs

using System;

public class Supervisor : SupportHandler {
  public override void HandleRequest(string request) {
    if (request == "Intermediate Issue") {
      Console.WriteLine($"Supervisor: Handling request - {request}");
    } else if (NextHandler != null) {
      NextHandler.HandleRequest(request); // Only pass if not handled
    } else {
      Console.WriteLine($"No handler available for - {request}");
    }
  }
}
