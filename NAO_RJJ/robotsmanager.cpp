#include "robotsmanager.h"

RobotsManager::RobotsManager(float dxRobots)
{
    this->dxRobots=dxRobots;
}

/**
  * Robot 1 stay and robot 2 move
  */
void RobotsManager::goPositionAttack(Robot* robot1, Robot* robot2){
    //here robot are suposed to be one in front of the other
    robot2->getMotion()->moveInit();
    float dy=-((robot1->getMotion()->getPosition("Torso",1,true).at(1)-robot1->getOrigy())+(robot2->getMotion()->getPosition("Torso",1,true).at(1)-robot2->getOrigy()));
    cout << "dy : " << dy << endl;
    robot2->getMotion()->moveTo(0,dy,0);
    //robotOne -> open legs
    AL::ALValue joints = AL::ALValue::array("LHipRoll","LHipPitch","LKneePitch","LAnklePitch","LAnkleRoll","RHipRoll","RHipPitch","RKneePitch","RAnklePitch","RAnkleRoll");
    AL::ALValue times = AL::ALValue::array(1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f);
    AL::ALValue angles=AL::ALValue::array(0.7f,-0.6f,0.0f,-0.3f,0.0f,-0.7f,-0.6f,0.0f,-0.3f,0.0f);

    robot1->getMotion()->angleInterpolation(joints,angles,times,true);
  /*  float posX=robot2->getMotion()->getPosition("Torso",1,true).at(0);
    bool done=true;
    while(robot2->getMotion()->getPosition("Torso",1,true).at(0)<(posX+1.5f)){
          if(done==true){
            done=false;
            robot2->standUp();
            //theorically must stay at 0
            robot2->getMotion()->moveTo(1.5f-robot2->getMotion()->getPosition("Torso",1,true).at(0),0,0);
            done=true;
          }
    }//*/
}
