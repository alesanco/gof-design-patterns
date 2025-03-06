// Main.java

public class Main {
  public static void main(String[] args) {
    FileSystemComponent file1 = new File("document.txt");
    FileSystemComponent file2 = new File("photo.jpg");

    Folder folder1 = new Folder("My Documents");
    folder1.addComponent(file1);
    folder1.addComponent(file2);

    FileSystemComponent file3 = new File("video.mp4");
    Folder folder2 = new Folder("Media");
    folder2.addComponent(file3);
    folder2.addComponent(folder1);

    folder2.showDetails();
  }
}
