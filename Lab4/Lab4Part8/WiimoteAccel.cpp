#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "WiimoteAccel.h"

//constructor for WiimoteAccel class
WiimoteAccel::WiimoteAccel() {
    //openning directory for reading remote event
    fd = open("/dev/input/event0", O_RDONLY);
    if (fd == -1) {
        std::cerr << "Error: Could not open event file - forgot sudo?\n";
        exit(1);
    }
}

//destructor for WiimoteAccel class
WiimoteAccel::~WiimoteAccel() {
    //close the file decriptor
    close(fd);
}

//Listen to the events on the remote
void WiimoteAccel::Listen() {
    while (true) {
        // Read a packet of 32 bytes from Wiimote
        char buffer[16];
        read(fd, buffer, 16);
        // Extract code (byte 10) and value (byte 12) from packet
        int code = buffer[10];
        short acceleration = * (short *) (buffer + 12);
        //calling AccelerationEvent with the values above
        AccelerationEvent(code, acceleration);
    }
}

//print out the code and acceleration from the remote
void WiimoteAccel::AccelerationEvent(int code, short acceleration) {
    std::cout << "Code = " << code <<", acceleration = " << acceleration << '\n';
}
