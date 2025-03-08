// TrafficLight.cs

public class TrafficLight {
  private ITrafficLightState _state;

  public TrafficLight() {
    _state = new RedLight(); // Initial state
  }

  public void SetState(ITrafficLightState state) {
    _state = state;
  }

  public void Change() {
    _state.Handle(this);
  }
}
