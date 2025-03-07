// RemoteControl.cs

using System;

public class RemoteControl {
  private ICommand? _command;

  public void SetCommand(ICommand command) {
    _command = command;
  }

  public void PressButton() {
    if (_command != null) {
      _command.Execute();
    } else {
      Console.WriteLine("No command assigned to button.");
    }
  }
}
