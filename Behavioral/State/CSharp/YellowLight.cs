// YellowLight.cs

using System;

public class YellowLight : ITrafficLightState {
  public void Handle(TrafficLight trafficLight) {
    Console.WriteLine("Yellow Light - PREPARE!");
    trafficLight.SetState(new RedLight()); // Transition to Red
  }
}
