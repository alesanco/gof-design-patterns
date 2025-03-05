# main.py
from concrete_creator_a import ConcreteCreatorA
from concrete_creator_b import ConcreteCreatorB

if __name__ == "__main__":
  creator_a = ConcreteCreatorA()
  product_a = creator_a.create_product()
  product_a.use()

  creator_b = ConcreteCreatorB()
  product_b = creator_b.create_product()
  product_b.use()
