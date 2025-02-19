using System;

class Program {
  static void Main() {
    Singleton s1 = Singleton.GetInstance();
    Singleton s2 = Singleton.GetInstance();
    Console.WriteLine(s1 == s2); // Should print: True
  }
}
