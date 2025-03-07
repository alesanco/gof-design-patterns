// SugarDecorator.cs

public class SugarDecorator : CoffeeDecorator {
  public SugarDecorator(ICoffee coffee) : base(coffee) {}

  public override string GetDescription() {
    return decoratedCoffee.GetDescription() + ", Sugar";
  }

  public override double GetCost() {
    return decoratedCoffee.GetCost() + 0.5;
  }
}
