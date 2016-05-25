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

    cout << "Enter desired servo [1, 5]: ";
    cin >> servoNumber;
    
    switch(servoNumber) {
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

    cout << "Enter desired start angle (0, 180): ";
    cin >> startAngle;

    if (startAngle <= 0 || startAngle >= 180) {
	cout << "Invalid servo angle";
        return 0;
    }

    cout << "Enter desired end angle (0, 180): ";
    cin >> endAngle;

    if (endAngle < 5 || endAngle > 175) {
        cout << "Invalid servo angle";
        return 0;
    }
    
    cout << "Enter desired rotational speed/s: ";
    cin >> speed;

   
    int startPulse = degreeToOnDelay(startAngle);
    int endPulse = degreeToOnDelay(endAngle);
    int numOfPeriod = (abs(startAngle - endAngle)/speed) * 1000 / 20;
    cout << numOfPeriod;
    // Open device file on Linux file system
    GPIO gpio(servoNumber);
    // Generate PWM signal with 20ms period and 1.5ms on time.
    // Generate 400 periods, this will take 20ms * 400 iterations = 8s
    cout << "start";
    gpio.GeneratePWM(20000, startPulse, 100);
    cout << "rotate";
    gpio.GenerateVariablePWM(20000, startPulse, endPulse, numOfPeriod);
    cout << "end";
    gpio.GeneratePWM(20000, endPulse, 50);

    // Done
    return 0;
}
