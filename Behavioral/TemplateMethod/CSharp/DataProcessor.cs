// DataProcessor.cs

using System;

public abstract class DataProcessor {
  // Template method defining the structure of the algorithm
  public void Process() {
    ReadData();
    ProcessData();
    SaveData();
  }

  // Abstract method to be implemented by subclasses
  protected abstract void ReadData();

  // Concrete method with common behavior
  protected void ProcessData() {
    Console.WriteLine("Processing data...");
  }

  // Concrete method with common behavior
  protected void SaveData() {
    Console.WriteLine("Data saved successfully.");
  }
}
