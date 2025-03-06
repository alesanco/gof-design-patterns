# concrete_creator_b.py

from creator import Creator
from concrete_product_b import ConcreteProductB

class ConcreteCreatorB(Creator):
  def create_product(self) -> ConcreteProductB:
    return ConcreteProductB()
