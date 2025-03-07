// Main.java

public class Main {
  public static void main(String[] args) {
    Coffee basicCoffee = new SimpleCoffee();
    System.out.println(basicCoffee.getDescription() + " -> $" + basicCoffee.getCost());

    Coffee milkCoffee = new MilkDecorator(basicCoffee);
    System.out.println(milkCoffee.getDescription() + " -> $" + milkCoffee.getCost());

    Coffee sugarMilkCoffee = new SugarDecorator(milkCoffee);
    System.out.println(sugarMilkCoffee.getDescription() + " -> $" + sugarMilkCoffee.getCost());
  }
}
