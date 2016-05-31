#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "WiimoteBtns.h"

//constructor
WiimoteBtns::WiimoteBtns() {
    //open file descriptor
    fd = open("/dev/input/event2", O_RDONLY);
    //check for error
    if (fd == -1) {
        std::cerr << "Error: Could not open event file - forgot sudo?\n";
        exit(1);
    }
}

//destructor
WiimoteBtns::~WiimoteBtns() {
    //close file descriptor
    close(fd);
}

//Lsitenning to the events
void WiimoteBtns::Listen() {
    while (true) {
        // Read a packet of 32 bytes from Wiimote
        char buffer[32];
        read(fd, buffer, 32);
        // Extract code (byte 10) and value (byte 12) from packet
        int code = buffer[10];
        int value = buffer[12];
        //call ButtonEvent when a new Event is read
        ButtonEvent(code, value);
    }
}

//print out the event buttons
void WiimoteBtns::ButtonEvent(int code, int value) {
    std::cout << "Code = " << code << ", value = " << value << '\n';
}

