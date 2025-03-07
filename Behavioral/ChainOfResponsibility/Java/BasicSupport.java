// BasicSupport.java

public class BasicSupport extends SupportHandler {
  @Override
  public void handleRequest(String request) {
    if (request.equals("Basic Issue")) {
      System.out.println("BasicSupport: Handling request - " + request);
    } else if (nextHandler != null) {
      nextHandler.handleRequest(request); // Only pass if not handled
    } else {
      System.out.println("No handler available for - " + request);
    }
  }
}
