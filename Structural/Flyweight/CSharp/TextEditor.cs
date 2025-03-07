// TextEditor.cs

using System;
using System.Collections.Generic;

public class TextEditor {
  private readonly List<FlyweightCharacter> characters = new List<FlyweightCharacter>();

  public void AddCharacter(char symbol) {
    characters.Add(CharacterFactory.GetCharacter(symbol));
  }

  public void DisplayCharacters() {
    foreach (FlyweightCharacter character in characters) {
      character.Display();
    }
    Console.WriteLine($"Total unique characters in memory: {CharacterFactory.GetPoolSize()}");
  }
}
