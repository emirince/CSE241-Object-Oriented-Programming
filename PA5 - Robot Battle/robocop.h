#pragma once
#ifndef ROBOCOP_H
#define ROBOCOP_H
#include "Robot.h"
#include "humanic.h"

namespace PA5{

class robocop : public humanic{

public:

robocop(int newType, int newStrength, int newHit, std::string newName): humanic(newType, newStrength, newHit, newName){}

robocop(): humanic(){}

virtual std::string getType();

virtual int getDamage();

};

}
#endif