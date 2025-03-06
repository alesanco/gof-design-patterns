// IFileSystemComponent.h

#ifndef IFILESYSTEMCOMPONENT_H
#define IFILESYSTEMCOMPONENT_H

class IFileSystemComponent {
public:
  virtual ~IFileSystemComponent() = default;
  virtual void showDetails() const = 0;
};

#endif // IFILESYSTEMCOMPONENT_H
