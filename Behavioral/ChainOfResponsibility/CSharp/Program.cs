// Program.cs

using System;

class Program {
  static void Main() {
    SupportHandler basic = new BasicSupport();
    SupportHandler supervisor = new Supervisor();
    SupportHandler manager = new Manager();

    // Setting up the chain
    basic.SetNextHandler(supervisor);
    supervisor.SetNextHandler(manager);

    // Sending requests
    basic.HandleRequest("Basic Issue");
    basic.HandleRequest("Intermediate Issue");
    basic.HandleRequest("Advanced Issue");
    basic.HandleRequest("Unknown Issue");
  }
}
