// Program.cs

using System;

class Program {
  static void Main() {
    Logger logger1 = Logger.Instance;
    logger1.Log("Initializing the system...");

    Logger logger2 = Logger.Instance;
    logger2.Log("System running.");

    // Verify if both instances are the same
    Console.WriteLine($"Logger instances are the same: {logger1 == logger2}");
  }
}
