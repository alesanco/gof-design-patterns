// Logger.cs

using System;

public sealed class Logger {
  private static Logger? instance;
  private static readonly object lockObject = new();

  private Logger() {
    Console.WriteLine("Logger instance created.");
  }

  public static Logger Instance {
    get {
      lock (lockObject) {
        if (instance == null) {
          instance = new Logger();
        }
        return instance;
      }
    }
  }

  public void Log(string message) {
    Console.WriteLine($"[LOG]: {message}");
  }
}
