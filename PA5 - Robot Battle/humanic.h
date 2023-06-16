#pragma once
#ifndef HUMANIC_H
#define HUMANIC_h
#include "Robot.h"

namespace PA5{

class humanic : public Robot{
private:

public:

humanic(): Robot(){}

humanic(int newType, int newStrength, int newHit, std::string newName): Robot(newType, newStrength, newHit, newName){}

virtual std::string getType();

virtual int getDamage();

};
}
#endif