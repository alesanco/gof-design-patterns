// CharacterFactory.java

import java.util.HashMap;
import java.util.Map;

public class CharacterFactory {
  private static final Map<Character, FlyweightCharacter> characterPool = new HashMap<>();

  public static FlyweightCharacter getCharacter(char symbol) {
    characterPool.putIfAbsent(symbol, new FlyweightCharacter(symbol));
    return characterPool.get(symbol);
  }

  public static int getPoolSize() {
    return characterPool.size();
  }
}
