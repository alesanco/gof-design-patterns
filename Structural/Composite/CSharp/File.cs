// File.cs

using System;

public class File : IFileSystemComponent {
  private string name;

  public File(string name) {
    this.name = name;
  }

  public void ShowDetails() {
    Console.WriteLine($"File: {name}");
  }
}
