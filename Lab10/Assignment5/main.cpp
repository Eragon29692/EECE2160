#include "RoboticArm.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
using namespace std;
int main()
{
    //file descriptors to the axis and buttons events
    int fd1;
    int fd2;
    //Acceleration events
    fd1 = open("/dev/input/event0", O_RDONLY | O_NONBLOCK);
    if (fd1 == -1) {
        std::cerr << "Error: Could not open event file - forgot sudo?\n";
        exit(1);
    }
    //Button events
    fd2 = open("/dev/input/event2", O_RDONLY | O_NONBLOCK);
    //check for error
    if (fd1 == -1) {
        std::cerr << "Error: Could not open event file - forgot sudo?\n";
        exit(1);
    }

    //set the servos initial angle
    RoboticArm robotic_arm;
    int angle0 = 90;
    int angle1 = 90;
    int angle2 = 90;
    int angle3 = 90;
    int angle4 = 90;

    //slow down time
    int stime = 8000;

    //counting until the slow down time for each button/axis
    int button103 = 0;
    int button108 = 0;
    int button105 = 0;
    int button106 = 0;
    int button48 = 0;
    int button49 = 0;
    int xTime = 0;
    int yTime = 0;

    //delayed Acceleration values
    int xAccel = 0;
    int yAccel = 0;

    //
    while (true)
    {
        // Read a packet of 32 bytes from Wiimote
        char buffer1[16];
        read(fd1, buffer1, 16);
        // Extract code (byte 10) and value (byte 12) from packet
        int code1 = buffer1[10];
        short acceleration = * (short *) (buffer1 + 12);
        //read X axis value
        if (code1 == 3) {
            xAccel = acceleration;
        }
        //read y axis value
        if (code1 == 4) {
            yAccel = acceleration;
        }


        char buffer2[32];
        read(fd2, buffer2, 32);
        // Extract code (byte 10) and value (byte 12) from packet
        int code2 = buffer2[10];
        int value = buffer2[12];


        //turn the remote left
        if (xAccel > 30) {
            xTime++;
            //check for valid angle and slow down time
            if (angle0 < 179 && xTime > stime) {
                angle0++;
                xTime = 0;
            }
        }
        //turn remote right
        if (xAccel < -50) {
            xTime++;
            //check for valid angle and slow down time
            if (angle0 > 0 && xTime > stime) {
                angle0--;
                xTime = 0;
            }
        }
        //turn remote up
        if (yAccel > -80) {
            yTime++;
            //check for valid angle and slow down time
            if (angle1 > 0 && yTime > stime) {
                angle1--;
                yTime = 0;
            }
        }
        //turn it down
        if (yAccel < -20) {
            yTime++;
            //check for valid angle and slow down time
            if (angle1 < 179 && yTime > stime) {
                angle1++;
                yTime = 0;
            }
        }

        //button up
        if (code2 == 103) {
            if (value == 0) {
                button103 = 0;
            }
            else {
                button103++;
                if (angle3 < 179 && button103 > stime) {
                    angle3++;
                    button103 = 0;
                }
            }
        }

        //button down
        if (code2 == 108) {
            if (value == 0) {
                button108 = 0;
            }
            else {
                button108++;
                if (angle3 > 0 && button108 > stime) {
                    angle3--;
                    button108 = 0;
                }
            }
        }

        //button right
        if (code2 == 105) {
            if (value == 0) {
                button105 = 0;
            }
            else {
                button105++;
                if (angle2 < 179 && button105 > stime) {
                    angle2++;
                    button105 = 0;
                }
            }
        }

        //button left
        if (code2 == 106) {
            if (value == 0) {
                button106 = 0;
            }
            else {
                button106++;
                if (angle2 > 0 && button106 > stime) {
                    angle2--;
                    button106 = 0;
                }
            }
        }

        //button trigger
        if (code2 == 49) {
            if (value == 0) {
                button49 = 0;
            }
            else {
                button49++;
                if (angle4 > 0 && button49 > stime - 5000) {
                    angle4--;
                    button49 = 0;
                }
            }
        }

        //button A
        if (code2 == 48) {
            if (value == 0) {
                button48 = 0;
            }
            else {
                button48++;
                if (angle4 < 179 && button48 > stime - 5000) {
                    angle4++;
                    button48 = 0;
                }
            }
        }

        //move the rbotic arm to the angle
        robotic_arm.MoveServo(3, angle3, 90);
        robotic_arm.MoveServo(0, angle0, 40);
        robotic_arm.MoveServo(1, angle1, 90);
        robotic_arm.MoveServo(2, angle2, 40);
        robotic_arm.MoveServo(4, angle4, 180);
    }
}
