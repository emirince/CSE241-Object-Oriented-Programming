#include "world.h"
#include "Robot.h"
#include "humanic.h"
#include "roomba.h"
#include "bulldozer.h"
#include "robocop.h"
#include "optimusprime.h"

using namespace std;

namespace PA5{

void World::createWorld(){

    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)         //we initialize the grid with robot objects
        {
            grid[i][j] = new Robot;    
        }  
    }
    
    int robotCount = 0; 
    int row;
    int column;

    while(robotCount!=20){
        row = rand()%10;
        column = rand()%10;

        bool duplicateFound = false;
    
        for (int i = 0; i < robotCount; i++)
        {
            if(reserved[i][0]==row && reserved[i][1]==column)                
            {
                duplicateFound = true;          //if the coordinates is already at the array, its not put on the reserved array
                break;
            }
            
        }
        
        if(duplicateFound)  continue;

        reserved[robotCount][0] = row;
        reserved[robotCount][1] = column;

        robotCount++;
    }

    grid[reserved[0][0]][reserved[0][1]] = new optimusprime(0,100,100,"optimusprime_0");        //we put optimusprime objects to grid
    grid[reserved[1][0]][reserved[1][1]] = new optimusprime(0,100,100,"optimusprime_1");
    grid[reserved[2][0]][reserved[2][1]] = new optimusprime(0,100,100,"optimusprime_2");
    grid[reserved[3][0]][reserved[3][1]] = new optimusprime(0,100,100,"optimusprime_3");
    grid[reserved[4][0]][reserved[4][1]] = new optimusprime(0,100,100,"optimusprime_4");

    grid[reserved[5][0]][reserved[5][1]] = new robocop(1,30,40,"robocop_0");        //we put robocop objects to grid
    grid[reserved[6][0]][reserved[6][1]] = new robocop(1,30,40,"robocop_1");
    grid[reserved[7][0]][reserved[7][1]] = new robocop(1,30,40,"robocop_2");
    grid[reserved[8][0]][reserved[8][1]] = new robocop(1,30,40,"robocop_3");
    grid[reserved[9][0]][reserved[9][1]] = new robocop(1,30,40,"robocop_4");

    grid[reserved[10][0]][reserved[10][1]] = new roomba(2,3,10,"roomba_0");         //we put roomba objects to grid
    grid[reserved[11][0]][reserved[11][1]] = new roomba(2,3,10,"roomba_1");
    grid[reserved[12][0]][reserved[12][1]] = new roomba(2,3,10,"roomba_2");
    grid[reserved[13][0]][reserved[13][1]] = new roomba(2,3,10,"roomba_3");
    grid[reserved[14][0]][reserved[14][1]] = new roomba(2,3,10,"roomba_4");


    grid[reserved[15][0]][reserved[15][1]] = new bulldozer(3,50,200,"bulldozer_0");     //we put bulldozer objects to grid
    grid[reserved[16][0]][reserved[16][1]] = new bulldozer(3,50,200,"bulldozer_1");
    grid[reserved[17][0]][reserved[17][1]] = new bulldozer(3,50,200,"bulldozer_2");
    grid[reserved[18][0]][reserved[18][1]] = new bulldozer(3,50,200,"bulldozer_3");
    grid[reserved[19][0]][reserved[19][1]] = new bulldozer(3,50,200,"bulldozer_4");
}


void World::simulateGame(){
    
    Robot* selectedRobot = new Robot;

    int selectedRobotRow;

    int selectedRobotColumn;

    while(remainingRobots > 1)
    {   
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE ; j++)
            {
                if (grid[i][j]->getType()=="optimusprime")
                    cout << "A";

                else if(grid[i][j]->getType()=="robocop")
                    cout << "B";                                         //by this nested loop we can print the map 

                else if(grid[i][j]->getType()=="roomba")
                    cout << "C";

                else if(grid[i][j]->getType()=="bulldozer")
                    cout << "D";
                
                else    
                    cout << ".";
            }
        cout << endl;
    }

    cout << endl << endl;

        bool stop = false;

        for (int i = 0; i < GRID_SIZE && !stop; i++)
        {
            if (i%2 == 0)           //Its for the rows 0,2,4,6,8th rows
            {
                for (int j = 0; j < GRID_SIZE && !stop; j++)
                { 
                    if (grid[i][j]->getType()=="optimusprime" || grid[i][j]->getType()=="robocop" || grid[i][j]->getType()=="roomba" || grid[i][j]->getType()=="bulldozer") //checks if its a robot derived from robot class
                    {    
                        selectedRobot = grid[i][j];
                        selectedRobotRow = i;
                        selectedRobotColumn = j;
                        stop = true;
                    }
                }    
            }
            else{
                for (int j = 9; j >= 0 && !stop; j--)       //Its for the rows 1,3,5,7,9th rows
                { 
                    if (grid[i][j]->getType()=="optimusprime" || grid[i][j]->getType()=="robocop" || grid[i][j]->getType()=="roomba" || grid[i][j]->getType()=="bulldozer")    //checks if its a robot derived from robot class
                    {    
                        selectedRobot = grid[i][j];
                        selectedRobotRow = i;
                        selectedRobotColumn = j;
                        stop = true;
                    }
                }
            }
        }

        if(tryMove(selectedRobot, selectedRobotRow, selectedRobotColumn)){          //If there is nothing on its way returns true
            moveRobot(selectedRobot, selectedRobotRow, selectedRobotColumn);        //Moves the robot
        }
        else{
            fightSelection(selectedRobot, selectedRobotRow, selectedRobotColumn);       //else sends robot to fight
        }
    
        string character;
        cout << "Please press any key to continue" << endl;
        getline(cin, character);
    }

    // if(remainingRobots==1){

    //     for (int i = 0; i < GRID_SIZE; i++)
    //     {
    //         for (int j = 0; j < GRID_SIZE ; j++)
    //         {
    //             if (grid[i][j]->getType()=="optimusprime")
    //                 cout << "A";

    //             else if(grid[i][j]->getType()=="robocop")
    //                 cout << "B";

    //             else if(grid[i][j]->getType()=="roomba")
    //                 cout << "C";

    //             else if(grid[i][j]->getType()=="bulldozer")
    //                 cout << "D";
                
    //             else    
    //                 cout << ".";
    //         }
    //     cout << endl;
    // }

        
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {   
                if (grid[i][j]->getType()=="optimusprime" || grid[i][j]->getType()=="robocop" || grid[i][j]->getType()=="roomba" || grid[i][j]->getType()=="bulldozer")
                {    
                    cout << "The winner is " << grid[i][j]->getName() << "!" << endl;
                }
            }
            
        }
        
    }



void World::fightSelection(Robot* selectedRobot, int Row, int Column){

    if(Row%2 == 0 && Column == 9){
        fight(selectedRobot,grid[Row+1][9],Row,9,Row+1,9);
        return;
    }

    else if(Row%2 == 1 && Column == 0){
        fight(selectedRobot,grid[Row+1][0],Row,0,Row+1,0);
        return;
    }

    else if(Row%2 == 0 && Column != 9){
        fight(selectedRobot,grid[Row][Column+1],Row,Column,Row,Column+1);
        return;
    }

    else if(Row%2 == 1 && Column != 0){
        fight(selectedRobot,grid[Row][Column-1],Row,Column,Row,Column-1);
        return;
    }    
}


void World::moveRobot(Robot* selectedRobot, int Row, int Column){

    Robot* temp = new Robot;
    
    temp = grid[Row][Column];           //stores the robot info
    grid[Row][Column] = new Robot;      //empties the location

    if(Row%2 == 0 && Column == 9){       //moves the robot accoring to its location
        grid[Row+1][9] = temp;
        return;
    }

    else if(Row%2 == 1 && Column == 0){
        grid[Row+1][0] = temp;
        return;
    }

    else if(Row%2 == 0 && Column != 9){
        grid[Row][Column+1] = temp;
        return;
    }

    else if(Row%2 == 1 && Column != 0){
        grid[Row][Column-1] = temp;
        return;
    }    
}


bool World::tryMove(Robot* selectedRobot, int Row, int Column){         //checks if there is a robot on selectedRobots way

    if(Row%2 == 0 && Column == 9){     
        if(grid[Row+1][9]->getType() == "optimusprime" || grid[Row+1][9]->getType() == "robocop" || grid[Row+1][9]->getType() == "roomba" ||grid[Row+1][9]->getType() == "bulldozer"){
            return false;
        }
        else{
            return true;
        }   
    }

    else if(Row%2 == 1 && Column == 0){
        if(grid[Row+1][0]->getType() == "optimusprime" || grid[Row+1][0]->getType() == "robocop" || grid[Row+1][0]->getType() == "roomba" ||grid[Row+1][0]->getType() == "bulldozer"){
            return false;
        }
        else{
            return true;
        }   
    }

    else if(Row%2 == 0 && Column != 9){
        if(grid[Row][Column+1]->getType() == "optimusprime" || grid[Row][Column+1]->getType() == "robocop" || grid[Row][Column+1]->getType() == "roomba" ||grid[Row][Column+1]->getType() == "bulldozer"){
            return false;
        }
        else{
            return true;
        }  
    }

    else if(Row%2 == 1 && Column != 0){
        if(grid[Row][Column-1]->getType() == "optimusprime" || grid[Row][Column-1]->getType() == "robocop" || grid[Row][Column-1]->getType() == "roomba" ||grid[Row][Column-1]->getType() == "bulldozer"){
            return false;
        }
        else{
            return true;
        }  
    }

    return true;
}

void World::fight(Robot* attackerRobot, Robot* defenderRobot,int attackerRow, int attackerColumn, int defenderRow, int defenderColumn){

    int turn = 0;

    string attackerName  = attackerRobot->getName();
    string victimName = defenderRobot->getName();

    int hitDamage;

    Robot* temp = new Robot;


    while(attackerRobot->getHit() > 0 && defenderRobot->getHit() > 0)
    {
        hitDamage = 0;

        if(turn % 2 == 0){              //If turn is even number, attacker robot attacks
            hitDamage = attackerRobot->getDamage();
            cout << attackerName << "(" << attackerRobot->getHit() << ")" << "hits " << victimName << "(" << defenderRobot->getHit() << ") with " << hitDamage << endl;
            
            defenderRobot->getHit() = defenderRobot->getHit() - hitDamage; 

            cout << "The new hitpoints of " << victimName << " is " << defenderRobot->getHit() << endl << endl;

            turn++;
        }

        else{                           //If turn is odd number, defender robot attacks
            hitDamage = defenderRobot->getDamage();
            cout << victimName << "(" << defenderRobot->getHit() << ")" << "hits " << attackerName << "(" << attackerRobot->getHit() << ") with " << hitDamage << endl;
       
            attackerRobot->getHit() = attackerRobot->getHit() - hitDamage;  
        
            cout << "The new hitpoints of " << attackerName << " is " << attackerRobot->getHit() << endl << endl;

            turn++;
        }
    }

    if (attackerRobot->getHit() < 0)        //If attacker robot is dead, it prints
    {   
        cout << attackerRobot->getName() << " is dead" << endl << endl;
        delete attackerRobot;
        grid[attackerRow][attackerColumn] = new Robot;
    }
    
    else{                                   //If defender robot is dead, it prints
        cout << defenderRobot->getName() << " is dead" << endl << endl;
        delete defenderRobot;
        grid[defenderRow][defenderColumn] = attackerRobot;
        grid[attackerRow][attackerColumn] = new Robot;
         
    }

    --remainingRobots;
}

}