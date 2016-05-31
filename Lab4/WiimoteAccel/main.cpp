#include <stdlib.h>
#include "WiimoteAccel.h"

//main program
int main() {
    //creating an object WiimoteAccel
    WiimoteAccel wiiAccel;
    //listenning to the event
    wiiAccel.Listen();
    return 0;

}