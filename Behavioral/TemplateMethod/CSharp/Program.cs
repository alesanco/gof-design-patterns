// Program.cs

using System;

class Program {
  static void Main() {
    DataProcessor csvProcessor = new CSVProcessor();
    csvProcessor.Process();

    Console.WriteLine("---------------------");

    DataProcessor jsonProcessor = new JSONProcessor();
    jsonProcessor.Process();
  }
}
