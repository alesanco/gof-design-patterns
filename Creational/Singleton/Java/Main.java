// Main.java

public class Main {
  public static void main(String[] args) {
    Logger logger1 = Logger.getInstance();
    logger1.log("Initializing the system...");

    Logger logger2 = Logger.getInstance();
    logger2.log("System running.");

    // Verify if both instances are the same
    System.out.println("Logger instances are the same: " + (logger1 == logger2));
  }
}
