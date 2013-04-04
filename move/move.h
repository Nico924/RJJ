#ifndef MOVE_H
#define MOVE_H

#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>

using namespace std;

class Move
{
public:
    Move(char* ip);
    void moveHead();
    void tryMove();
    void lyingBack();
    void standUp();
    void showPostureList();
    void shrimpPosition();
    void setHeadRight();
    void moveSpecificJoint(std::string jointName,float radian);

private:
    char *ip;
    AL::ALMotionProxy* motion;
    AL::ALRobotPostureProxy* posture;

};

#endif // MOVE_H
