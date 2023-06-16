#ifndef ROOMBA_H
#define ROOMBA_H
#include "Robot.h"
#include <iostream>
#include <cstdlib>
#include <cmath> 

namespace PA5{

class roomba : public Robot{
private:

public:

roomba(): Robot(2,0,0," "){}

roomba(int newType, int newStrength, int newHit, std::string newName): Robot(newType, newStrength, newHit, newName){}

virtual  std::string getType();

virtual int getDamage();

};

}

#endif