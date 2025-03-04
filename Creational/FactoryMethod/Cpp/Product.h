#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
public:
  virtual void use() = 0;
  virtual ~Product() = default;
};

#endif // PRODUCT_H
