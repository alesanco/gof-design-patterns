// Main.java

public class Main {
  public static void main(String[] args) {
    SupportHandler basic = new BasicSupport();
    SupportHandler supervisor = new Supervisor();
    SupportHandler manager = new Manager();

    // Setting up the chain
    basic.setNextHandler(supervisor);
    supervisor.setNextHandler(manager);

    // Sending requests
    basic.handleRequest("Basic Issue");
    basic.handleRequest("Intermediate Issue");
    basic.handleRequest("Advanced Issue");
    basic.handleRequest("Unknown Issue");
  }
}
