// Folder.h

#ifndef FOLDER_H
#define FOLDER_H

#include "IFileSystemComponent.h"
#include <vector>
#include <memory>
#include <iostream>

class Folder : public IFileSystemComponent {
private:
  std::string name;
  std::vector<std::unique_ptr<IFileSystemComponent>> components;

public:
  Folder(const std::string& name);
  void addComponent(std::unique_ptr<IFileSystemComponent> component);
  void showDetails() const override;
};

#endif // FOLDER_H
