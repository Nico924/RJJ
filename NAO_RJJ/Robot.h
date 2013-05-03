#ifndef ROBOT_H
#define ROBOT_H


#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <cmath>

using namespace std;

class Robot
{
public:
    Robot(char* ip,int port);
    void moveHead();
    void tryMove();
    void lyingBack();
    void standUp();
    void showPostureList();
    void shrimpPosition();
    void setHeadRight();
    void moveSpecificJoint(std::string jointName,float radian);
    AL::ALMotionProxy* getMotion();
    AL::ALRobotPostureProxy* getRobotPosture();
private:
    AL::ALMotionProxy* motion;
    AL::ALRobotPostureProxy* posture;
};

#endif // ROBOT_H
