#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "world.h"
#include "Robot.h"
#include "humanic.h"
#include "roomba.h"
#include "robocop.h"
#include "optimusprime.h"
#include "bulldozer.h"

int main(){

srand(time(NULL));

PA5::World world1;

world1.createWorld();

world1.simulateGame();

return 0;
}