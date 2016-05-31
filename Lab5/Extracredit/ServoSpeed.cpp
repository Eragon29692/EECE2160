#include "GPIO.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int degreeToOnDelay(int degree) {
    return (degree * 10) + 600;
}


int main()
{
    int servoNumber1;
    int startAngle1;
    int endAngle1;
    int speed1;
    int servoNumber2;
    int startAngle2;
    int endAngle2;
    int speed2;


    cout << "Enter desired servo 1 [1, 5]: ";
    cin >> servoNumber1;
    cout << "Enter desired servo 2 [1, 5]: ";
    cin >> servoNumber2;

    switch (servoNumber1) {
    case 1:
        servoNumber1 = 13;
        break;
    case 2:
        servoNumber1 = 10;
        break;
    case 3:
        servoNumber1 = 11;
        break;
    case 4:
        servoNumber1 = 12;
        break;
    case 5:
        servoNumber1 = 0;
        break;
    default:
        cout << "Invalid servo number";
        return 0;
        break;
    }

    switch (servoNumber2) {
    case 1:
        servoNumber2 = 13;
        break;
    case 2:
        servoNumber2 = 10;
        break;
    case 3:
        servoNumber2 = 11;
        break;
    case 4:
        servoNumber2 = 12;
        break;
    case 5:
        servoNumber2 = 0;
        break;
    default:
        cout << "Invalid servo number";
        return 0;
        break;
    }


    //start angle
    cout << "Enter desired start angle (0, 180): ";
    cin >> startAngle1;

    cout << "Enter desired start angle (0, 180): ";
    cin >> startAngle2


    if (startAngle1 <= 0 || startAngle1 >= 180) {
        cout << "Invalid servo angle";
        return 0;
    }

    if (startAngle2 <= 0 || startAngle2 >= 180) {
        cout << "Invalid servo angle";
        return 0;
    }

    //endAngle
    cout << "Enter desired end angle (0, 180): ";
    cin >> endAngle1;

    if (endAngle1 < 5 || endAngle1 > 175) {
        cout << "Invalid servo angle";
        return 0;
    }

    cout << "Enter desired end angle (0, 180): ";
    cin >> endAngle2;

    if (endAngle2 < 5 || endAngle2 > 175) {
        cout << "Invalid servo angle";
        return 0;
    }

    //speed
    cout << "Enter desired rotational speed/s: ";
    cin >> speed1;

    cout << "Enter desired rotational speed/s: ";
    cin >> speed2;


    //calculation
    int startPulse1 = degreeToOnDelay(startAngle1);
    int endPulse1 = degreeToOnDelay(endAngle1);
    int numOfPeriod1 = (abs(startAngle1 - endAngle1)/speed1) * 1000 / 20;

    int startPulse2 = degreeToOnDelay(startAngle2);
    int endPulse2 = degreeToOnDelay(endAngle2);
    int numOfPeriod2 = (abs(startAngle2 - endAngle2)/speed2) * 1000 / 20;


    // Open device file on Linux file system
    GPIO gpio(servoNumber1, servoNumber2);

    cout << "start";
    gpio.GeneratePWM(20000, startPulse1, startAngle2, 100);
    cout << "rotate";
    gpio.GenerateVariablePWM(20000, startPulse1, endPulse1, numOfPeriod1, startPulse2, endPulse2, numOfPeriod2);
    cout << "end";
    gpio.GeneratePWM(20000, endPulse1, endPulse2, 100);

    // Done
    return 0;
}
