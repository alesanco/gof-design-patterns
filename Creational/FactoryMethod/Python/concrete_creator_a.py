# concrete_creator_a.py
from creator import Creator
from concrete_product_a import ConcreteProductA

class ConcreteCreatorA(Creator):
  def create_product(self) -> ConcreteProductA:
    return ConcreteProductA()
