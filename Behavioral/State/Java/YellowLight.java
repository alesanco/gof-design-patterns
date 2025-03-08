// YellowLight.java

public class YellowLight implements TrafficLightState {
  @Override
  public void handle(TrafficLight trafficLight) {
    System.out.println("Yellow Light - PREPARE!");
    trafficLight.setState(new RedLight()); // Transition to Red
  }
}
