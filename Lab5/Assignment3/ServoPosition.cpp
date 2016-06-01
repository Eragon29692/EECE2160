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
    int servoAngle;
    //getting the servo number
    cout << "Enter desired servo [1, 5]: ";
    cin >> servoNumber;
    //converting the servo number to the actually servo port
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

    //getting the angle
    cout << "Enter desired angle [5, 175]: ";
    cin >> servoAngle;

    //check for valid angle
    if (servoAngle < 5 || servoAngle > 175) {
        cout << "Invalid servo angle";
        return 0;
    }

    // Open device file on Linux file system
    GPIO gpio(servoNumber);
    // Generate PWM signal with 20ms period and 1.5ms on time.
    // Generate 400 periods, this will take 20ms * 400 iterations = 8s
    gpio.GeneratePWM(20000, degreeToOnDelay(servoAngle), 400);
    // Done
    return 0;
}
