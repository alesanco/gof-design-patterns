// BasicSupport.cs

using System;

public class BasicSupport : SupportHandler {
  public override void HandleRequest(string request) {
    if (request == "Basic Issue") {
      Console.WriteLine($"BasicSupport: Handling request - {request}");
    } else if (NextHandler != null) {
      NextHandler.HandleRequest(request); // Only pass if not handled
    } else {
      Console.WriteLine($"No handler available for - {request}");
    }
  }
}
