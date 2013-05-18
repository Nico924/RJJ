/**
 * Copyright (c) 2011 Aldebaran Robotics. All Rights Reserved
 *
 * \file movehead.cpp
 * \brief Move NAO's head.
 *
 * A simple example showing how to move NAO's head by using ALMotionProxy.
 * This example will make NAO turn its head left and right slowly.
 * We use here a specialized proxy to ALMotion.
 */



#include <iostream>
#include "move.h"
#include "robot.h"
#include "robotsmanager.h"


int main(int argc, char* argv[]) {
    bool oneRobot=false;
    if(argc==3){
        oneRobot=true;
    }
    else if(argc != 2)
    {
        cerr << "Wrong number of arguments!" << endl;
        cerr << "Usage: move NAO_IP" << endl;
        exit(2);
    }
    bool continueProgram=true;
    string input,inputJoint;
    float angle;
    float dx,dy;
    Robot* robotOne,*robotTwo;
    robotOne=new Robot(argv[1],9559);
    if(!oneRobot)
        robotTwo=new Robot(argv[1],9560);
    //small init
    Robot* currentRobot=robotOne;
    RobotsManager robotsManager;
    //position absolute for the world start position !!!!!
    //x in front of the robot, y on his left and theta is the angle around z
    //robot two is looking at robot one
    //origine is robot one
    robotOne->setAbsPos(0.0f,0.0f,0.0f,0.10f);
    if(!oneRobot)
        robotTwo->setAbsPos(1.0f,0.0f,PI);
    cout << "Input something to continue (stand then init): help for help" << endl << "IMPORTANT : Wait that the robot stop moving to type another command !"<<endl;
    while(continueProgram)
    {
        cin >> input;
        //small functionnalities
        if(input=="stand"){
            robotOne->standUp();
            robotTwo->standUp();
        }
        else if(input=="robot1"){
            currentRobot=robotOne;
        }
        else if(input=="robot2"){
            currentRobot=robotTwo;
        }
        else if(input=="exit"){
            continueProgram=false;
        }
        else if(input=="posAttack"){
            //currentRobot have to be in position lying back
            currentRobot->lyingBack();
            if(currentRobot==robotOne){
                 robotsManager.goPositionAttack(currentRobot,robotTwo);
            }
            else{
                robotsManager.goPositionAttack(currentRobot,robotOne);
            }
        }
        else if(input=="moveTo"){
            cout << "Enter dx, dy, dthéta (by pressing enter each time)"<<endl;
            cin >> dx;
            cin >> dy;
            cin >> angle;
            currentRobot->getMotion()->moveTo(dx,dy,angle);
        }
        else if(input=="move"){
            cout << "Enter relative dx, dy, dthéta (by pressing enter each time)\n "<<endl;
            cin >> dx;
            cin >> dy;
            cin >> angle;
            currentRobot->moveRel(dx,dy,angle);
        }
        else if(input=="go"){
            if(currentRobot==robotOne){
                 robotsManager.moveRobots(currentRobot,robotTwo);
            }
            else{
                robotsManager.moveRobots(currentRobot,robotOne);
            }
        }
        else if(input=="grab"){
            currentRobot->grabOpponent();
        }
        else if(input=="goCrouch"){
            currentRobot->goCrouch();
        }
        else if(input=="openLegs"){
            currentRobot->putLegsUp();
            currentRobot->swerveLegs();
        }
        else if(input=="getPos"){
            cout << currentRobot->getAbsPos() << endl;
            vector<float> pos=currentRobot->getMotion()->getPosition("CameraTop",1,true);
            cout <<"CameraTop : "<<endl<< pos << endl;
        }
        else if(input=="attack"){
            currentRobot->attack();
        }
        else if(input=="pos"){
            cout << "Input a joint name (see doc)" << endl;
            cin >> inputJoint;
            cout << currentRobot->getMotion()->getPosition(inputJoint,1,true) << endl;

        }
        //for only one robot
        else if(input=="standup"){
            currentRobot->standUp();
        }
        else if(input=="crouch"){
            currentRobot->getRobotPosture()->goToPosture("Crouch",0.5f);
        }
        else if(input=="lyingBack"){
            currentRobot->lyingBack();
        }
        else if(input=="shrimp"){
            currentRobot->setHeadRight();
            currentRobot->shrimpPosition();
            currentRobot->endShrimp();
        }
        else if(input=="endShrimp"){
            currentRobot->endShrimp();
        }
       /* else if(input=="red"){
            currentRobot->detectRedBall();
        }*/
        else if(input=="moveJoint"){
            cout << "Input a joint name (see doc)" << endl;
            cin >> inputJoint;
            cout << "Input a angle (float) (see doc)" << endl;
            cin >> angle;
            currentRobot->moveSpecificJoint(inputJoint,angle);
        }
        else if(input=="help"){
                cout << "Command are:\nFOR BOTH:\nstand\ninit\nposAttack\nFOR ONE:\nrobot1 to use robot1\nrobot2 tu use only robot2\nmoveTo\nstandup \nlyingBack \nshrimp \nmoveJoint\nhelp\nexit "<<endl;
         }
        else{
            cout << "wrond command ! type help for help" << endl;
        }

    }

    exit(0);
}

