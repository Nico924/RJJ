#ifndef ROBOT_H
#define ROBOT_H


#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <cmath>
#include <alproxies/alsonarproxy.h>
#include <alproxies/allaserproxy.h>

using namespace std;

class Robot
{
public:
    Robot(char* ip,int port);
    void init();
    void computeInfo();
    void moveHead();
    void tryMove();
    void lyingBack();
    void standUp();
    void putLegsUp();
    void showPostureList();
    void shrimpPosition();
    void setHeadRight();
    void moveSpecificJoint(std::string jointName,float radian);
    AL::ALMotionProxy* getMotion();
    AL::ALRobotPostureProxy* getRobotPosture();
    float getOrigx();
    float getOrigy();
    float getOrigTheta();
private:
    AL::ALMotionProxy* motion;
    AL::ALRobotPostureProxy* posture;
    AL::ALLaserProxy *laser;
    float origX,origY,origTheta;
};

#endif // ROBOT_H
