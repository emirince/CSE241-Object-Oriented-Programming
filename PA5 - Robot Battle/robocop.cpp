#include "robocop.h"

namespace PA5{
std::string robocop::getType(){
    return "robocop";
}

int robocop::getDamage(){
    int damage = humanic::getDamage();
    return damage;
}

}