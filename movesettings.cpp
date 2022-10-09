#include "movesettings.h"

MoveSettings::MoveSettings(){

};

int MoveSettings::getSpeed(){
    return this->movemant_speed;
}

void MoveSettings::setSpeed(int speed){
    this->movemant_speed = speed;
}

void MoveSettings::setSteps(int steps){
    this->num_of_steps = steps;
}

int MoveSettings::getSteps(){
   return this->num_of_steps;
}

void MoveSettings::runPattern(){
    patternRun(num_of_steps);
}

void MoveSettings::setPattern(void(*pat)(int)){
    patternRun = pat;
}

void* MoveSettings::getPattern(){
    return (void*)patternRun;
}


