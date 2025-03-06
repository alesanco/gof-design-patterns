// File.h

#ifndef FILE_H
#define FILE_H

#include "IFileSystemComponent.h"
#include <iostream>
#include <string>

class File : public IFileSystemComponent {
private:
  std::string name;

public:
  File(const std::string& name);
  void showDetails() const override;
};

#endif // FILE_H
