// Program.cs

using System;

class Program {
  static void Main() {
    TrafficLight trafficLight = new TrafficLight();

    for (int i = 0; i < 6; i++) {
      trafficLight.Change();
    }
  }
}
