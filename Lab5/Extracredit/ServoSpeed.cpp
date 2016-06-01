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

    //getting the 2 servo which will be moved
    cout << "Enter desired servo 1 [1, 5]: ";
    cin >> servoNumber1;
    cout << "Enter desired servo 2 [1, 5]: ";
    cin >> servoNumber2;

    //converting the servo number 1 to the actual servo port
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

    //converting the servo number 2 to the actual servo port
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


    //getting the start angle 1
    cout << "Enter desired start angle 1 (5, 175): ";
    cin >> startAngle1;
    //checking for valid start angle 1
    if (startAngle1 < 5 || startAngle1 > 175) {
        cout << "Invalid servo angle";
        return 0;
    }
    //gettign the start angle 2
    cout << "Enter desired start angle 2 (5, 175): ";
    cin >> startAngle2;
    //checking for valid starting angle
    if (startAngle2 < 5 || startAngle2 > 175) {
        cout << "Invalid servo angle";
        return 0;
    }

    //endAngle
    cout << "Enter desired end angle 1 (5, 175): ";
    cin >> endAngle1;
    //checking for valid and angle
    if (endAngle1 < 5 || endAngle1 > 175) {
        cout << "Invalid servo angle";
        return 0;
    }
    //gettign the angle
    cout << "Enter desired end angle 2 (5, 175): ";
    cin >> endAngle2;
    //checking for valid end angle
    if (endAngle2 < 5 || endAngle2 > 175) {
        cout << "Invalid servo angle";
        return 0;
    }

    //getting speed 2
    cout << "Enter desired rotational speed/s: ";
    cin >> speed1;

    //getting speed 2
    cout << "Enter desired rotational speed/s: ";
    cin >> speed2;

    //calculation for the first servo
    int startPulse1 = degreeToOnDelay(startAngle1);
    int endPulse1 = degreeToOnDelay(endAngle1);
    int numOfPeriod1 = (abs(startAngle1 - endAngle1)/speed1) * 1000 / 20;

    //calculation for the second servo
    int startPulse2 = degreeToOnDelay(startAngle2);
    int endPulse2 = degreeToOnDelay(endAngle2);
    int numOfPeriod2 = (abs(startAngle2 - endAngle2)/speed2) * 1000 / 20;

	
    // Open device file on Linux file system
    GPIO gpio(servoNumber1, servoNumber2);


    //getting the servos to the starting posiotions
    gpio.GeneratePWM(20000, startPulse1, startPulse2, 200);
    //moving the servo to the ending position base on the calculated speed
    gpio.GenerateVariablePWM(20000, startPulse1, endPulse1, numOfPeriod1, startPulse2, endPulse2, numOfPeriod2);
    //holding the servos at the endign position for 2 seconds
    gpio.GeneratePWM(20000, endPulse1, endPulse2, 200);

    //Done
    return 0;

}