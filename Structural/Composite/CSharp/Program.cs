// Program.cs

using System;

class Program {
  static void Main() {
    IFileSystemComponent file1 = new File("document.txt");
    IFileSystemComponent file2 = new File("photo.jpg");

    Folder folder1 = new Folder("My Documents");
    folder1.AddComponent(file1);
    folder1.AddComponent(file2);

    IFileSystemComponent file3 = new File("video.mp4");
    Folder folder2 = new Folder("Media");
    folder2.AddComponent(file3);
    folder2.AddComponent(folder1);

    folder2.ShowDetails();
  }
}
