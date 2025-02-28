#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
public:
  virtual void use() = 0; // Pure virtual function
  virtual ~Product() {}   // Virtual destructor for proper cleanup
};

#endif // PRODUCT_H
