#include "Singleton.cpp"

Singleton* Singleton::instance = nullptr; // Define the static member

Singleton* Singleton::GetInstance() {
  if (instance == nullptr) {
    instance = new Singleton();
  }
  return instance;
}
