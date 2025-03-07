// Supervisor.java

public class Supervisor extends SupportHandler {
  @Override
  public void handleRequest(String request) {
    if (request.equals("Intermediate Issue")) {
      System.out.println("Supervisor: Handling request - " + request);
    } else if (nextHandler != null) {
      nextHandler.handleRequest(request); // Only pass if not handled
    } else {
      System.out.println("No handler available for - " + request);
    }
  }
}
