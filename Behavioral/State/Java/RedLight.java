// RedLight.java

public class RedLight implements TrafficLightState {
  @Override
  public void handle(TrafficLight trafficLight) {
    System.out.println("Red Light - STOP!");
    trafficLight.setState(new GreenLight()); // Transition to Green
  }
}
