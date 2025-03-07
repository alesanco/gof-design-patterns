// TurnOffCommand.java

public class TurnOffCommand implements Command {
  private Light light;

  public TurnOffCommand(Light light) {
    this.light = light;
  }

  @Override
  public void execute() {
    light.turnOff();
  }
}
