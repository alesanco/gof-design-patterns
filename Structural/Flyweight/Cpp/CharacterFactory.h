// CharacterFactory.h

#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H

#include "FlyweightCharacter.h"
#include <unordered_map>

class CharacterFactory {
private:
  static std::unordered_map<char, FlyweightCharacter*> characterPool;

public:
  static FlyweightCharacter* getCharacter(char symbol);
  static int getPoolSize();
  static void cleanup();
};

#endif // CHARACTER_FACTORY_H
