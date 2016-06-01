#include "GPIO.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int degreeToOnDelay(int degree) {
    return (degree * 10) + 600;
}


int main()
{
    int servoNumber;
    int startAngle;
    int endAngle;
    int speed;

    //getting the servo number
    cout << "Enter desired servo [1, 5]: ";
    cin >> servoNumber;

    //converting the servo number to the actual servo port
    switch (servoNumber) {
    case 1:
        servoNumber = 13;
        break;
    case 2:
        servoNumber = 10;
        break;
    case 3:
        servoNumber = 11;
        break;
    case 4:
        servoNumber = 12;
        break;
    case 5:
        servoNumber = 0;
        break;
    default:
        cout << "Invalid servo number";
        return 0;
        break;
    }

    //getting the starting angle of the servo
    cout << "Enter desired start angle (0, 180): ";
    cin >> startAngle;

    //check for a valid angle
    if (startAngle <= 0 || startAngle >= 180) {
        cout << "Invalid servo angle";
        return 0;
    }

    //getiing the ending angle for the servo
    cout << "Enter desired end angle (0, 180): ";
    cin >> endAngle;

    //cehcking for valid angle
    if (endAngle < 5 || endAngle > 175) {
        cout << "Invalid servo angle";
        return 0;
    }

    //getting the desired speed for the servo in degree/second
    cout << "Enter desired rotational speed/s: ";
    cin >> speed;

    //calculating the starting pulse ending pulse
    //and the number of periods base on speed
    int startPulse = degreeToOnDelay(startAngle);
    int endPulse = degreeToOnDelay(endAngle);
    int numOfPeriod = (abs(startAngle - endAngle)/speed) * 1000 / 20;

    // Open device file on Linux file system
    GPIO gpio(servoNumber);
    //getting into starting position for 1 second
    gpio.GeneratePWM(20000, startPulse, 50);
    //slowly moving to the ending poition
    gpio.GenerateVariablePWM(20000, startPulse, endPulse, numOfPeriod);
    //staying at the ending posiotion for 1 second
    gpio.GeneratePWM(20000, endPulse, 50);

    // Done
    return 0;
}
