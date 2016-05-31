#include <stdlib.h>
#include "WiimoteAccel.h"
#include "ZedBoard.h"

//WiimoteToLed class
class WiimoteToLed : public WiimoteAccel {
private:
    //pointer to zedBoard
    ZedBoard *zedB;
public:
    //constructor
    WiimoteToLed(ZedBoard *zedBoard) {
        zedB = zedBoard;
    }

    //override the default acceleration event
    void AccelerationEvent(int code, short acceleration) {
        //read only the events from the x axis
        if (code != 3) {
            return;
        }
        //check and make sure the acceleration is in range [-100, 100]
        if (acceleration > 100)
            acceleration = 100;
        if (acceleration < -100)
            acceleration = -100;

        //converting the acceleration into scale of 8
        int numberOfLed = abs(acceleration * 8 / 100);
        int i;
        //set the LEDs base on the acceleration
        for (i = 0; i < 8; i++) {
            if (i < numberOfLed)
                zedB->setLed(i, 1);
            else
                zedB->setLed(i, 0);
        }
    }
};

int main()
{
    // Instantiate ZedBoard object statically
    ZedBoard zed_board;

    // Instantiate WiimoteToLed object statically, passing a pointer to the
    // recently created ZedBoard object.
    WiimoteToLed wiimote_to_led(&zed_board);

    // Enter infinite loop listening to events. The overridden function
    // WiimoteToLed::AccelerationEvent() will be invoked when the user moves
    // the Wiimote.
    wiimote_to_led.Listen();

    // Unreachable code, previous function has an infinite loop
    return 0;
}


