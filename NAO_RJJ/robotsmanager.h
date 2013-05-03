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
    RobotsManager(int dxOtherSystem);
    void moveTo(Robot *robot1,Robot *robot2);
private:
    int dxOtherSystem;
};

#endif // ROBOTSMANAGER_H
