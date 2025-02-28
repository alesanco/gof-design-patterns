// Main.java
public class Main {
  public static void main(String[] args) {
    Creator creatorA = new ConcreteCreatorA();
    Product productA = creatorA.createProduct();
    productA.use();

    Creator creatorB = new ConcreteCreatorB();
    Product productB = creatorB.createProduct();
    productB.use();
  }
}
