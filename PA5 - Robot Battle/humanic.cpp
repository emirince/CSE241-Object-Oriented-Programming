#include "humanic.h"
#include "Robot.h"
#include <string>
#include <cmath>
#include <cstdlib>

namespace PA5{

std::string humanic::getType(){
    switch (type)
    {
        case 0: return "optimusprime";
        case 1: return "robocop";
    }
    return "unknown";
}

int humanic::getDamage(){

int damage = Robot::getDamage()+1;

int chance = (rand()%10)+1;

if(chance==1)
{
    damage = damage + 50;
}

return damage;

}
}