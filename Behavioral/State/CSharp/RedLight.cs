// RedLight.cs

using System;

public class RedLight : ITrafficLightState {
  public void Handle(TrafficLight trafficLight) {
    Console.WriteLine("Red Light - STOP!");
    trafficLight.SetState(new GreenLight()); // Transition to Green
  }
}
