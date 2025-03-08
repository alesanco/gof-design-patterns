// DataProcessor.java

public abstract class DataProcessor {
  
  // Template method defining the structure of the algorithm
  public final void process() {
    readData();
    processData();
    saveData();
  }

  // Abstract method to be implemented by subclasses
  protected abstract void readData();

  // Concrete method with common behavior
  protected void processData() {
    System.out.println("Processing data...");
  }

  // Concrete method with common behavior
  protected void saveData() {
    System.out.println("Data saved successfully.");
  }
}
