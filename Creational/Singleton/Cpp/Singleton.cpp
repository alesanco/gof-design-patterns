class Singleton {
  private:
    static Singleton* instance;
    Singleton() {} // Private constructor

  public:
    static Singleton* GetInstance();
};
