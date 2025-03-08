// Iterator.h

#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class Iterator {
public:
  virtual ~Iterator() = default;
  virtual bool hasNext() = 0;
  virtual T next() = 0;
};

#endif // ITERATOR_H
