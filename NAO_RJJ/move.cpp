#include "move.h"

Move::Move(char* ip)
{
    this->ip=ip;
    try{
        this->motion=new AL::ALMotionProxy(this->ip,9559);
        this->posture=new AL::ALRobotPostureProxy(this->ip);
    }
    catch (const AL::ALError& e) {
        cerr << "Caught exception: " << e.what() << std::endl;
        exit(1);
    }
}
void Move::moveHead(){
    /** The name of the joint to be moved. */
    const AL::ALValue jointName = "HeadYaw";

    /** Target stiffness. */
    AL::ALValue stiffness = 1.0f;
    /** Time (in seconds) to reach the target. */
    AL::ALValue time = 1.0f;
    /** Call the stiffness interpolation method. */
    motion->stiffnessInterpolation(jointName, stiffness, time);

    /** Set the target angle list, in radians. */
    AL::ALValue targetAngles = AL::ALValue::array(-1.5f, 1.5f, 0.0f);
    /** Set the corresponding time lists, in seconds. */
    AL::ALValue targetTimes = AL::ALValue::array(3.0f, 6.0f, 9.0f);
    /** Specify that the desired angles are absolute. */
    bool isAbsolute = true;

    /** Call the angle interpolation method. The joint will reach the
         * desired angles at the desired times.
         */
    motion->angleInterpolation(jointName, targetAngles, targetTimes, isAbsolute);

    /** Remove the stiffness on the head. */
    stiffness = 0.0f;
    time = 1.0f;
    motion->stiffnessInterpolation(jointName, stiffness, time);

}
void Move::tryMove(){
    // Example showing how Initialize move process.
    motion->moveInit();
    // Example showing the moveTo command
    // as length of path is less than 0.4m
    // the path will be an SE3 interpolation
    // The units for this command are meters and radians
    float x  = 0.5f;
    float y  = 0.5f;
    // pi/2 anti-clockwise (90 degrees)
    float theta = 1.2709f;
    motion->moveTo(x, y, theta);
    // Will block until walk Task is finished

    // Example showing the moveTo command
    // as length of path is more than 0.4m
    // the path will be follow a dubins curve
    // The units for this command are meters and radians
    x  = -0.1f;
    y  = -0.5f;
    theta  = 0.0f;
    motion->moveTo(x, y, theta);
}
void Move::showPostureList(){
    vector<string> list=this->posture->getPostureList();
    for(int i=0;i<list.size();i++){
        cout << list.at(i) << endl;
    }
}

void Move::lyingBack(){
    this->posture->goToPosture("LyingBack",0.5f);
}
void Move::standUp(){
    this->posture->goToPosture("Stand",0.5f);
}
void Move::setHeadRight(){
    const AL::ALValue headJoint = AL::ALValue::array("HeadPitch","HeadYaw");
    AL::ALValue times = AL::ALValue::array(1.0f,1.0f);
    AL::ALValue angles=AL::ALValue::array(0.0f,0.0f);

    motion->angleInterpolation(headJoint,angles,times,true);

}
void Move::moveSpecificJoint(std::string jointName,float radian){
    const AL::ALValue joints = AL::ALValue::array(jointName);
    AL::ALValue angles=AL::ALValue::array(radian);
    AL::ALValue times = AL::ALValue::array(1.0f);
    motion->angleInterpolation(joints,angles,times,true);
}

void Move::shrimpPosition(){
    //if robot is in position LyingBack (have to had verif)

    // Puts leg up
    AL::ALValue joints = AL::ALValue::array("LHipRoll","LHipPitch","LKneePitch","LAnklePitch","LAnkleRoll","RHipRoll","RHipPitch","RKneePitch","RAnklePitch","RAnkleRoll");
    //AL::ALValue stiffness = 1.0f;
    AL::ALValue times = AL::ALValue::array(1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f);
    AL::ALValue angles=AL::ALValue::array(0.0f,-0.6f,0.0f,-0.3f,0.0f,0.0f,-0.6f,0.0f,-0.3f,0.0f);

    motion->angleInterpolation(joints,angles,times,true);

    // Puts arms up
    joints = AL::ALValue::array("LShoulderPitch","LShoulderRoll","LElbowYaw","LElbowRoll","LWristYaw","RShoulderPitch","RShoulderRoll","RElbowYaw","RElbowRoll","RWristYaw");
    angles=AL::ALValue::array(0.5f,0.0f,0.0f,0.0f,0.0f,0.5f,0.0f,0.0f,0.0f,0.0f);
    motion->angleInterpolation(joints,angles,times,true);

    //Move head and arm to the left
    joints = AL::ALValue::array("HeadPitch","HeadYaw","LShoulderRoll","RShoulderRoll","RElbowRoll","LHipRoll","RHipRoll","LAnklePitch","RAnklePitch");
    times = AL::ALValue::array(1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f);
    angles=AL::ALValue::array(0.5149f,1.1f,1.3265f,0.3142f,0.8f,0.790477f,0.4f,0.85f,0.9f);
    motion->angleInterpolation(joints,angles,times,true);

    //put legs down
    joints = AL::ALValue::array("RHipPitch","RKneePitch","LHipPitch","RAnkleRoll","RAnklePitch");
    times = AL::ALValue::array(1.0f,1.0f,1.0f,1.0,1.0f);
    angles = AL::ALValue::array(0.3f,1.6f,-0.09f,0.19f,0.2f);
    motion->angleInterpolation(joints,angles,times,true);

    //remove the stiffness of the foot in order to put it on the ground
    joints = AL::ALValue::array("RAnklePitch","RAnkleRoll");
    AL::ALValue stiffness=AL::ALValue::array(0.0f,0.0f);
    times = AL::ALValue::array(0.1f,0.1f);
    motion->stiffnessInterpolation(joints, stiffness, times);

    joints = AL::ALValue::array("LHipYawPitch","LShoulderRoll","LElbowRoll","LShoulderPitch");
    times = AL::ALValue::array(1.0f,1.0f,1.0f,1.0f);
    angles = AL::ALValue::array(-0.55f,0.81f,-0.7f,1.54f);
    motion->angleInterpolation(joints,angles,times,true);
   /* joints = AL::ALValue::array("RHipPitch");
    angles=AL::ALValue::array(0.8f);
    times = AL::ALValue::array(1.0f);
    motion->angleInterpolation(joints,angles,times,true);*/


}
