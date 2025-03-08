// TrafficLight.java

public class TrafficLight {
  private TrafficLightState state;

  public TrafficLight() {
    state = new RedLight(); // Initial state
  }

  public void setState(TrafficLightState state) {
    this.state = state;
  }

  public void change() {
    state.handle(this);
  }
}
