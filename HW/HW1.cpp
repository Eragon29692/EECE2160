#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <sys/mman.h>

int main()
{
    // Initialize the zedboard object
    ZedBoard zedB;
    //the current value indicated by the LEDs in integer
    int value = 0;
    //the currently pressed button
    int pressedButton = 0;
    //the button was pressed previously
    int previousPressed= 0;
    //number of tick per second
    int tickPerSec = 0;
    //number if unit increased per tick
    int increasePerTick = 1;

    //the idea is to have the LEDs display whatever the integer varialble has
    //all number operations are on the value variable and then set to the LEDs
    //using SetLedNumber function
    while (1)
    {
        //get the pressed button
        pressedButton = zedB.PushButtonGet();
        //check if the pressed button is the same as the previously pressed
        //this is to check for the "sticky" button cases
        if (pressedButton != previousPressed) {
            //update the previously pressed button
            previousPressed = pressedButton;
            //cases for each buttons
            switch (pressedButton)
            {
            case 1:
                //decrease 1 unit per tick
                increasePerTick = -1;
                break;
            case 2:
                //increase 1 unit per tick
                increasePerTick = 1;
                break;
            case 3:
                //increase number of tick per second
                tickPerSec++;
                break;
            case 4:
                //decrese number of tick per second
                tickPerSec--;
                break;
            case 5:
                //switch the value to what the switches has
                value = zedB.switchtoInteger();
                //set that value to the LEDs
                zedB.SetLedNumber(value);
                break;
            default:
                break;
            }
        }
        //do nothing if the tickPerSec is 0 to avoid division by 0 in usleep
        //inside is what to do per tick
        if (tickPerSec) {
            //a sleep period in each second
            usleep(1000000/tickPerSec);
            //increase value per tick
            value += increasePerTick;
            //set the updated value to the LEDs
            zedB.SetLedNumber(value);
        }
    }
    return 0;
}