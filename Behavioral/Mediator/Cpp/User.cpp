// User.cpp

#include "User.h"

User::User(Mediator* mediator, std::string name) : mediator(mediator), name(std::move(name)) {}
