#include "optimusprime.h"
#include "Robot.h"
#include "humanic.h"
#include <cmath>
#include <string>
#include <cstdlib>

namespace PA5{

std::string optimusprime::getType(){
    return "optimusprime";
}

int optimusprime::getDamage(){

int damage = Robot::getDamage();

int chance = (rand()%100)+1;

if(chance >= 0 && chance <=15){        //by 15 percent chance the damage is multiplied by 2
    damage = damage * 2;
}

chance = (rand()%10)+1;                 //by 10 percent chance 50 is added to damage

if(chance==1)
{
    damage = damage + 50;
}

return damage;
}
}