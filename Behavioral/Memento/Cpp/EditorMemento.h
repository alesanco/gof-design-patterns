// EditorMemento.h

#ifndef EDITORMEMENTO_H
#define EDITORMEMENTO_H

#include <string>

class EditorMemento {
private:
  std::string content;

public:
  explicit EditorMemento(const std::string& content);
  std::string getContent() const;
};

#endif // EDITORMEMENTO_H
