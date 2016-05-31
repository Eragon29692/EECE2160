#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <sys/mman.h>
#include "ZedBoard.h"

//contructor for ZedBoard class
ZedBoard::ZedBoard() {
    //openning directory for reading the remote memory
    fd = open( "/dev/mem", O_RDWR);
    //check for opening file descriptor error
    if (fd == -1) {
        std::cerr << "Error: Could not open event file - forgot sudo?\n";
        exit(1);
    }
    //memory mapping for read/write to the device memory
    pBase = (char *) mmap(
                NULL,
                gpio_size,
                PROT_READ | PROT_WRITE,
                MAP_SHARED,
                fd,
                gpio_address);
    //check for memory mapping failures
    if (pBase == MAP_FAILED)
    {
        std::cerr << "Mapping I/O memory failed - Did you run with 'sudo'?\n";
        exit(1);
    }

}

//ZedBoard class destructor
ZedBoard::~ZedBoard() {
    close(fd);
}

//write to output device memory
void ZedBoard::RegisterWrite(int offset, int value) {
    * (int *) (pBase + offset) = value;
}

//read from input device memory
int ZedBoard::RegisterRead(int offset) {
    return * (int *) (pBase + offset);
}

//set the LED states on the ZedBoard base on value
void ZedBoard::setLed(int led, int value) {
    //switch cases for which LED to be set
    switch (led) {
    case 0 :
        led = gpio_led1_offset;
        break;
    case 1 :
        led = gpio_led2_offset;
        break;
    case 2 :
        led = gpio_led3_offset;
        break;
    case 3 :
        led = gpio_led4_offset;
        break;
    case 4 :
        led = gpio_led5_offset;
        break;
    case 5 :
        led = gpio_led6_offset;
        break;
    case 6 :
        led = gpio_led7_offset;
        break;
    case 7 :
        led = gpio_led8_offset;
        break;
    default:
        std::cout << "Invalid LED number";
        return;
    }
    //Check for the valid state of the LED
    if (value != 0 && value != 1) {
        std::cout << "Invalid value";
        return;
    }
    //write to the LED memory
    RegisterWrite(led, value);
}

