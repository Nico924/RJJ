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

    if(argc != 2)
    {
        cerr << "Wrong number of arguments!" << endl;
        cerr << "Usage: move NAO_IP" << endl;
        exit(2);
    }
    bool continueProgram=true;
    string input,inputJoint;
    float angle;
    float dx,dy;
    Robot* robotOne=new Robot(argv[1],9559);
    Robot* robotTwo=new Robot(argv[1],9560);
    //small init
    Robot* currentRobot=robotOne;
    RobotsManager robotsManager(1.2f);

    cout << "Input something to continue (stand then init): help for help" << endl << "IMPORTANT : Wait that the robot stop moving to type another command !"<<endl;
    while(continueProgram)
    {
        cin >> input;
        //small functionnalities
        if(input=="stand"){
            robotOne->standUp();
            robotTwo->standUp();
        }
        else if(input=="getAll"){
            currentRobot->computeInfo();
        }
        else if(input=="init"){
            robotOne->init();
            robotTwo->init();
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
        else if(input=="attack"){
            //the robot that will be attacked have to be in Crouch positon between legs of the other robots
        }
        else if(input=="moveTo"){
            cout << "Enter dx, dy, dthéta (by pressing enter each time)"<<endl;
            cin >> dx;
            cin >> dy;
            cin >> angle;
            currentRobot->getMotion()->moveTo(dx,dy,angle);
        }
        else if(input=="getPos"){
            cout << currentRobot->getMotion()->getRobotPosition(false) << endl;
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
        }
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

