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

void launchShrimp();

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
    robotOne->standUp();
    robotTwo->standUp();
    Robot* currentRobot=robotOne;
    RobotsManager robotsManager(7);

    cout << "Input something to continue : help for help" << endl << "IMPORTANT : Wait that the robot stop moving to type another command !"<<endl;
    while(continueProgram)
    {
        cin >> input;
        if(input=="robot1"){
            currentRobot=robotOne;
        }
        else if(input=="robot2"){
            currentRobot=robotTwo;
        }
        else if(input=="exit"){
            continueProgram=false;
        }
        else if(input=="attack"){
            if(currentRobot==robotOne){
                 robotsManager.moveTo(currentRobot,robotTwo);
            }
            else{
                robotsManager.moveTo(currentRobot,robotOne);
            }
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
        else if(input=="standup"){
            currentRobot->standUp();
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
                cout << "Command are:\nrobot1 to use robot1\nrobot2 tu use only robot2\nattack\nmove to\nstandup \nlyingBack \nshrimp \nmoveJoint\nhelp\n exit "<<endl;
            }
        else{
            cout << "wrond command ! type help for help" << endl;
        }

    }

    exit(0);
}

