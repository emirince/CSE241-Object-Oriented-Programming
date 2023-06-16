#include "Robot.h"
#include "humanic.h"
#include "roomba.h"
#include "bulldozer.h"
#include "robocop.h"
#include "optimusprime.h"

namespace PA5{

const int NUMBER_OF_RAUNDS = 19;

const int GRID_SIZE = 10;

class World{

friend class Robot;
friend class humanic;
friend class roomba;
friend class bulldozer;
friend class robocop;
friend class optimusprime;

public:

Robot* grid[GRID_SIZE][GRID_SIZE];

int reserved[20][2];

int remainingRobots = 20;

void createWorld();

void simulateGame();

void fightSelection(Robot* selectedRobot, int Row, int Column);

void moveRobot(Robot* selectedRobot, int Row, int Column);

bool tryMove(Robot* selectedRobot, int Row, int Column);

void fight(Robot* attackerRobot, Robot* defenderRobot,int attackerRow, int attackerColumn, int defenderRow, int defenderColumn);
};
}