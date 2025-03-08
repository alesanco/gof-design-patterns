// GreenLight.java

public class GreenLight implements TrafficLightState {
  @Override
  public void handle(TrafficLight trafficLight) {
    System.out.println("Green Light - GO!");
    trafficLight.setState(new YellowLight()); // Transition to Yellow
  }
}
