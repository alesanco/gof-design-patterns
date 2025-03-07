// CharacterFactory.cpp

#include "CharacterFactory.h"

std::unordered_map<char, FlyweightCharacter*> CharacterFactory::characterPool;

FlyweightCharacter* CharacterFactory::getCharacter(char symbol) {
  if (characterPool.find(symbol) == characterPool.end()) {
    characterPool[symbol] = new FlyweightCharacter(symbol);
  }
  return characterPool[symbol];
}

int CharacterFactory::getPoolSize() {
  return characterPool.size();
}

void CharacterFactory::cleanup() {
  for (auto& pair : characterPool) {
    delete pair.second;
  }
  characterPool.clear();
}
