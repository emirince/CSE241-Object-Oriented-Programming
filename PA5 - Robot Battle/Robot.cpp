#include "Robot.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

namespace PA5{

string Robot::getName(){
    return name;
}

int& Robot::getHit(){
    return hit;
}


int& Robot::getStrength(){
    return strength;
}

string Robot::getType(){
    switch (type)
    {
        case 0: return "optimusprime";
        case 1: return "robocop";
        case 2: return "roomba";
        case 3: return "bulldozer"; 
    }
    return "unknown";
}

int Robot::getDamage(){

int damage = (rand()%strength)+1;

return damage;
}
}