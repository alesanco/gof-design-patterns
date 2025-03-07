// CoffeeDecorator.cs

public abstract class CoffeeDecorator : ICoffee {
  protected ICoffee decoratedCoffee;

  public CoffeeDecorator(ICoffee coffee) {
    this.decoratedCoffee = coffee;
  }

  public virtual string GetDescription() {
    return decoratedCoffee.GetDescription();
  }

  public virtual double GetCost() {
    return decoratedCoffee.GetCost();
  }
}
