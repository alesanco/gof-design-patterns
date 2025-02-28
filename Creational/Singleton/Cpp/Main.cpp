// Main.cpp
#include <iostream>
#include "Singleton.h"

int main() {
  Singleton* s1 = Singleton::GetInstance();
  Singleton* s2 = Singleton::GetInstance();

  std::cout << (s1 == s2) << std::endl; // Should print: 1 (true)

  // Cleanup memory
  Singleton::DestroyInstance();

  return 0;
}
