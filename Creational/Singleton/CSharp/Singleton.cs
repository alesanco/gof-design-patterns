public class Singleton {
  private static Singleton? instance = null;
  
  private Singleton() {} // Private constructor

  public static Singleton GetInstance() {
    if (instance == null) {
      instance = new Singleton();
    }
    return instance;
  }
}
