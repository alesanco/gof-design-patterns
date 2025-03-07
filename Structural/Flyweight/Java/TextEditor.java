// TextEditor.java

import java.util.ArrayList;
import java.util.List;

public class TextEditor {
  private final List<FlyweightCharacter> characters = new ArrayList<>();

  public void addCharacter(char symbol) {
    characters.add(CharacterFactory.getCharacter(symbol));
  }

  public void displayCharacters() {
    for (FlyweightCharacter character : characters) {
      character.display();
    }
    System.out.println("Total unique characters in memory: " + CharacterFactory.getPoolSize());
  }
}
