# main.py

from file import File
from folder import Folder

if __name__ == "__main__":
  file1 = File("document.txt")
  file2 = File("photo.jpg")

  folder1 = Folder("My Documents")
  folder1.add_component(file1)
  folder1.add_component(file2)

  file3 = File("video.mp4")
  folder2 = Folder("Media")
  folder2.add_component(file3)
  folder2.add_component(folder1)

  folder2.show_details()
