#include "robotsmanager.h"

RobotsManager::RobotsManager(int dxOtherSystem)
{
    this->dxOtherSystem=dxOtherSystem;
}
/**
  * Robot 1 stay and robot 2 move
  */
void RobotsManager::moveTo(Robot* robot1, Robot* robot2){
    bool useSensorValues = false;
    std::vector<float> resultOne = robot1->getMotion()->getRobotPosition(useSensorValues);
    std::cout << "Robot one is at position: " << resultOne << std::endl;
    std::vector<float> resultTwo = robot2->getMotion()->getRobotPosition(useSensorValues);
    std::cout << "Robot two is at position: " << resultTwo << std::endl;
    float x1,x2,y1,y2,theta1,theta2;
    x1=resultOne.at(0);
    x2=resultTwo.at(0);
    y1=resultOne.at(1);
    y2=resultTwo.at(1);
    theta1=resultOne.at(2);
    theta2=resultTwo.at(2);
    robot2->getMotion()->moveInit();
    //first they have to look at the same direction
  //  while(robot1->getMotion()->getRobotPosition(useSensorValues).at(2))

    float dx,dy,dtheta;
    dx=x1-x2;
    dy=y1-y2;
    dtheta=resultOne.at(2)-resultTwo.at(2);
    cout << "dist (x,y,theta) =("<<  dx <<"," << dy << "," << dtheta <<")" << endl;
//robot2->getMotion()->moveTo(dx,dy,dtheta);
    robot2->getMotion()->moveTo(0,0,0);
    robot1->getMotion()->moveTo(0,0,0);

}
