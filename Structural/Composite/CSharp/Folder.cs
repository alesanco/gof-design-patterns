// Folder.cs

using System;
using System.Collections.Generic;

public class Folder : IFileSystemComponent {
  private string name;
  private List<IFileSystemComponent> components = new List<IFileSystemComponent>();

  public Folder(string name) {
    this.name = name;
  }

  public void AddComponent(IFileSystemComponent component) {
    components.Add(component);
  }

  public void ShowDetails() {
    Console.WriteLine($"Folder: {name}");
    foreach (var component in components) {
      component.ShowDetails();
    }
  }
}
