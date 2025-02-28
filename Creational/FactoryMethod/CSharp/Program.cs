// Program.cs
using System;

class Program {
  static void Main() {
    Creator creatorA = new ConcreteCreatorA();
    IProduct productA = creatorA.CreateProduct();
    productA.Use();

    Creator creatorB = new ConcreteCreatorB();
    IProduct productB = creatorB.CreateProduct();
    productB.Use();
  }
}
