#ifndef MOVESETTINGS_H
#define MOVESETTINGS_H
#include <QPoint>
#include <QCursor>
#include <QThread>

class MoveSettings
{
public:
    MoveSettings();
    void moveSquare();
    int getSpeed();
    void setSpeed(int speed);
    int getSteps();
    void setSteps(int steps);
    void setPattern(void(*pat)(int));
    void* getPattern();
    void runPattern();
private:
    int movemant_speed;
    int num_of_steps;
    void(*patternRun)(int);

};

#endif // MOVESETTINGS_H
