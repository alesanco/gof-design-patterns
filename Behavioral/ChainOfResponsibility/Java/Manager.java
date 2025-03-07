// Manager.java

public class Manager extends SupportHandler {
  @Override
  public void handleRequest(String request) {
    if (request.equals("Advanced Issue")) {
      System.out.println("Manager: Handling request - " + request);
    } else {
      System.out.println("No handler available for - " + request);
    }
  }
}
