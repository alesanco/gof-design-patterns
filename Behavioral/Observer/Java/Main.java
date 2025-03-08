// Main.java

public class Main {
  public static void main(String[] args) {
    NewsAgency agency = new NewsAgency();

    Observer subscriber1 = new EmailSubscriber("Alice");
    Observer subscriber2 = new SMSSubscriber("Bob");
    Observer subscriber3 = new EmailSubscriber("Charlie");

    agency.addObserver(subscriber1);
    agency.addObserver(subscriber2);
    agency.addObserver(subscriber3);

    agency.notifyObservers("Breaking News: Observer Pattern Implemented!");
    
    agency.removeObserver(subscriber2);

    agency.notifyObservers("Update: Java Observer Example Completed!");
  }
}
