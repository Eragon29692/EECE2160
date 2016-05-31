#include <stdlib.h>
#include "WiimoteBtns.h"

//main program
int main() {
    //create an object of WiimoteBtns
    WiimoteBtns wiiButton;
    //Listen to the event
    wiiButton.Listen();
    return 0;
}

