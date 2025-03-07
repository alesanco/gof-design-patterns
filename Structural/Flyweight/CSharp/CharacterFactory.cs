// CharacterFactory.cs

using System;
using System.Collections.Generic;

public static class CharacterFactory {
  private static readonly Dictionary<char, FlyweightCharacter> characterPool = new Dictionary<char, FlyweightCharacter>();

  public static FlyweightCharacter GetCharacter(char symbol) {
    if (!characterPool.ContainsKey(symbol)) {
      characterPool[symbol] = new FlyweightCharacter(symbol);
    }
    return characterPool[symbol];
  }

  public static int GetPoolSize() {
    return characterPool.Count;
  }
}
