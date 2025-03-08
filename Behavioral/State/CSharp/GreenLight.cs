// GreenLight.cs

using System;

public class GreenLight : ITrafficLightState {
  public void Handle(TrafficLight trafficLight) {
    Console.WriteLine("Green Light - GO!");
    trafficLight.SetState(new YellowLight()); // Transition to Yellow
  }
}
