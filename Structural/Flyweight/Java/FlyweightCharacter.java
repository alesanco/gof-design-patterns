// FlyweightCharacter.java

public class FlyweightCharacter {
  private final char symbol;

  public FlyweightCharacter(char symbol) {
    this.symbol = symbol;
  }

  public void display() {
    System.out.println("Character: " + symbol);
  }
}
