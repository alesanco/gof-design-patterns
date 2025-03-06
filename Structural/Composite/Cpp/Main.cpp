// Main.cpp

#include "File.h"
#include "Folder.h"
#include <memory>

int main() {
  auto file1 = std::make_unique<File>("document.txt");
  auto file2 = std::make_unique<File>("photo.jpg");

  auto folder1 = std::make_unique<Folder>("My Documents");
  folder1->addComponent(std::make_unique<File>("document.txt"));
  folder1->addComponent(std::make_unique<File>("photo.jpg"));

  auto file3 = std::make_unique<File>("video.mp4");
  auto folder2 = std::make_unique<Folder>("Media");
  folder2->addComponent(std::make_unique<File>("video.mp4"));
  folder2->addComponent(std::move(folder1));

  folder2->showDetails();

  return 0;
}
