#include <iostream>
#include <cstdlib>
#include <cmath> 
#include "roomba.h"

namespace PA5{

std::string roomba::getType(){
    return "roomba";
}

int roomba::getDamage(){
    int damage1 = Robot::getStrength();
    int damage2 = Robot::getStrength();

    return (damage1 + damage2);
}
}