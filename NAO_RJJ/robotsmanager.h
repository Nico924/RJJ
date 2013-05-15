#ifndef ROBOTSMANAGER_H
#define ROBOTSMANAGER_H

#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include "robot.h"

using namespace std;


class RobotsManager
{
public:
    RobotsManager(float dxRobots);
    void goPositionAttack(Robot *robot1,Robot *robot2);
private:
    float dxRobots;
};

#endif // ROBOTSMANAGER_H
