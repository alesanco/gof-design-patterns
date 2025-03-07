// Program.cs

using System;

class Program {
  static void Main() {
    ICoffee basicCoffee = new SimpleCoffee();
    Console.WriteLine($"{basicCoffee.GetDescription()} -> ${basicCoffee.GetCost()}");

    ICoffee milkCoffee = new MilkDecorator(basicCoffee);
    Console.WriteLine($"{milkCoffee.GetDescription()} -> ${milkCoffee.GetCost()}");

    ICoffee sugarMilkCoffee = new SugarDecorator(milkCoffee);
    Console.WriteLine($"{sugarMilkCoffee.GetDescription()} -> ${sugarMilkCoffee.GetCost()}");
  }
}
