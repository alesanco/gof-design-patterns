// Singleton.h
#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
private:
  static Singleton* instance;
  Singleton() {} // Private constructor

public:
  static Singleton* GetInstance();
  static void DestroyInstance();

  // Prevent copying
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
};

#endif // SINGLETON_H
