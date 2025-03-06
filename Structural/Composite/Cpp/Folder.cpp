// Folder.cpp

#include "Folder.h"

Folder::Folder(const std::string& name) : name(name) {}

void Folder::addComponent(std::unique_ptr<IFileSystemComponent> component) {
  components.push_back(std::move(component));
}

void Folder::showDetails() const {
  std::cout << "Folder: " << name << std::endl;
  for (const auto& component : components) {
    component->showDetails();
  }
}
