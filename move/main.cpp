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
    Move *myMove=new Move(argv[1]);
    cout << "Input something to continue : help for help" << endl << "IMPORTANT : Wait that the robot stop moving to type another command !"<<endl;
    while(continueProgram)
    {
        cin >> input;
        if(input=="standup"){
            myMove->standUp();
        }
        else if(input=="lyingBack"){
            myMove->lyingBack();
        }
        else if(input=="shrimp"){
            myMove->setHeadRight();
            myMove->shrimpPosition();
        }
        else if(input=="moveJoint"){
            cout << "Input a joint name (see doc)" << endl;
            cin >> inputJoint;
            cout << "Input a angle (float) (see doc)" << endl;
            cin >> angle;
            myMove->moveSpecificJoint(inputJoint,angle);
        }
        else if(input=="exit"){
            continueProgram=false;
        }
        else if(input=="help"){
            cout << "Command are : \n exit \n help \n standup \n lyingBack \n shrimp \n moveJoint "<<endl;
        }
        else{
            cout << "wrond command ! type help for help" << endl;
        }

    }

    exit(0);
}

