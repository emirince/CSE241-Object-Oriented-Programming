#ifndef BULLDOZER_H
#define BULLDOZER_H
#include "Robot.h"

namespace PA5{

class bulldozer : public Robot{
private:

public:

bulldozer(int newType, int newStrength, int newHit, std::string newName): Robot(newType, newStrength, newHit, newName){}

virtual std::string getType();
};

}
#endif 