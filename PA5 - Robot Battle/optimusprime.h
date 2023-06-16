#pragma once
#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H
#include "Robot.h"
#include "humanic.h"

namespace PA5{

class optimusprime : public humanic{

public: 

optimusprime(int newType, int newStrength, int newHit, std::string newName): humanic(newType, newStrength, newHit, newName){}

virtual std::string getType();

virtual int getDamage();

};

}
#endif