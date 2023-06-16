#ifndef ROBOT_H
#define ROBOT_H
#include <string>
#include <iostream>

namespace PA5{

class Robot{

protected:

int type;

int strength;

int hit;

std::string name;

public:

Robot(): type(-1), strength(0), hit(0), name(" ") {}

Robot(int newType, int newStrength, int newHit, std::string newName): type(newType), strength(newStrength), hit(newHit), name(newName){}  

std::string getName();


int& getHit();

int& getStrength();

virtual std::string getType();

virtual int getDamage();
};
}
#endif