// Singleton.cpp
#include "Singleton.h"

Singleton* Singleton::instance = nullptr;

Singleton* Singleton::GetInstance() {
  if (instance == nullptr) {
    instance = new Singleton();
  }

  return instance;
}

void Singleton::DestroyInstance() {
  delete instance;
  instance = nullptr;
}
