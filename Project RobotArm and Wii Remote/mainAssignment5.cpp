#include "RoboticArm.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
using namespace std;
int main()
{

    //set the servos initial angle
    RoboticArm robotic_arm;

    while (true)
    {
        //move the rbotic arm to the angle and open its arm
        robotic_arm.MoveServo(0, 0, 180);
        robotic_arm.MoveServo(1, 120, 90);
        robotic_arm.MoveServo(2, 90, 90);
        robotic_arm.MoveServo(3, 90, 40);
        robotic_arm.MoveServo(4, 180, 180);
        sleep(1);
        //go down close the hand
        robotic_arm.MoveServo(1, 135, 180);
        sleep(1);
        //close the arm's hand
        robotic_arm.MoveServo(4, 0, 180);
        //throw
        robotic_arm.MoveServo(1, 0, 180);
        robotic_arm.MoveServo(2, 180, 180);
        robotic_arm.MoveServo(3, 180, 180);
        sleep(1);
    }
}

