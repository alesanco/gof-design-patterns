// Main.java

public class Main {
  public static void main(String[] args) {
    DataProcessor csvProcessor = new CSVProcessor();
    csvProcessor.process();

    System.out.println("---------------------");

    DataProcessor jsonProcessor = new JSONProcessor();
    jsonProcessor.process();
  }
}
