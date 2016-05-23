#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <sys/mman.h>
#include "ZedBoard.h"

ZedBoard::ZedBoard() {
    fd = open( "/dev/mem", O_RDWR);
	
    if (fd == -1) {
        std::cerr << "Error: Could not open event file - forgot sudo?\n";
        exit(1);
    }
	
    pBase = (char *) mmap(
               NULL,
               gpio_size,
               PROT_READ | PROT_WRITE,
               MAP_SHARED,
               fd,
               gpio_address);
			   
    if (pBase == MAP_FAILED)
    {
        std::cerr << "Mapping I/O memory failed - Did you run with 'sudo'?\n";
        exit(1);
    }
 
}

ZedBoard::~ZedBoard() {
    close(fd);
}

void ZedBoard::RegisterWrite(int offset, int value) {
	* (int *) (pBase + offset) = value;
}

int ZedBoard::RegisterRead(int offset) {
    return * (int *) (pBase + offset);
}

void ZedBoard::setLed(int led, int value) {
    switch(led) {
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
    if (value != 0 && value != 1) {
    	std::cout << "Invalid value";
	return;
    }
    RegisterWrite(led, value);
}

