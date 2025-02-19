#include <iostream>
#include "Singleton.cpp"

int main() {
  Singleton* s1 = Singleton::GetInstance();
  Singleton* s2 = Singleton::GetInstance();
  std::cout << (s1 == s2) << std::endl; // Should print: 1 (true)
  return 0;
}
