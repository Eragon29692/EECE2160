#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <sys/mman.h>
// Physical base address of GPIO
const unsigned gpio_address = 0x400d0000;
// Length of memory-mapped IO window
const unsigned gpio_size = 0xff;
const int gpio_led1_offset = 0x12C; // Offset for LED1
const int gpio_led2_offset = 0x130; // Offset for LED2
const int gpio_led3_offset = 0x134; // Offset for LED3
const int gpio_led4_offset = 0x138; // Offset for LED4
const int gpio_led5_offset = 0x13C; // Offset for LED5
const int gpio_led6_offset = 0x140; // Offset for LED6
const int gpio_led7_offset = 0x144; // Offset for LED7
const int gpio_led8_offset = 0x148; // Offset for LED8
const int gpio_sw1_offset = 0x14C; // Offset for Switch 1
const int gpio_sw2_offset = 0x150; // Offset for Switch 2
const int gpio_sw3_offset = 0x154; // Offset for Switch 3
const int gpio_sw4_offset = 0x158; // Offset for Switch 4
const int gpio_sw5_offset = 0x15C; // Offset for Switch 5
const int gpio_sw6_offset = 0x160; // Offset for Switch 6
const int gpio_sw7_offset = 0x164; // Offset for Switch 7
const int gpio_sw8_offset = 0x168; // Offset for Switch 8
const int gpio_pbtnl_offset = 0x16C; // Offset for left push button
const int gpio_pbtnr_offset = 0x170; // Offset for right push button
const int gpio_pbtnu_offset = 0x174; // Offset for up push button
const int gpio_pbtnd_offset = 0x178; // Offset for down push button
const int gpio_pbtnc_offset = 0x17C; // Offset for center push button

class ZedBoard {
private:
    int fd;
    char *pBase;
public:
    /**
    * Initialize general-purpose I/O
                break;
    * - Opens access to physical memory /dev/mem
    * - Maps memory at offset 'gpio_address' into virtual address space
    *
    * @param fd File descriptor passed by reference, where the result
    * of fun        case 0 :
                led_index = gpio_led1_offset;
    ction 'open' will be stored.
    * @return Address to virtual memory which is mapped to physical,
    * or MAP_FAILED on error.
    */
    ZedBoard() {
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
	
    /**
    * Close general-purpose I/O.
    *
    * @param pBase Virtual address where I/O was mapped.
    * @param fd File descriptor previously returned by 'open'.
    */
    ~ZedBoard() {
        munmap(pBase, gpio_size);
        close(fd);
    }
	
    /**
    * Write a 4-byte value at the specified general-purpose I/O location.
    * @parem offset Offset where device is mapped.
    * @param value Value to be written.
    */
    void RegisterWrite(int offset, int value) {
        * (int *) (pBase + offset) = value;
    }
	
    /**
    * Read a 4-byte value from the specified general-purpose I/O location.
    * @param offset Offset where device is mapped.
    * @return Value read.
    */
    int RegisterRead(int offset) {
        return * (int *) (pBase + offset);
    }
	
    /**
    * Show lower 8 bits of integer value on LEDs
    * @param value Value to show on LEDs
    */
    void SetLedNumber(int value)
    {
        RegisterWrite(gpio_led1_offset, value % 2);
        RegisterWrite(gpio_led2_offset, (value / 2) % 2);
        RegisterWrite(gpio_led3_offset, (value / 4) % 2);
        RegisterWrite(gpio_led4_offset, (value / 8) % 2);
        RegisterWrite(gpio_led5_offset, (value / 16) % 2);
        RegisterWrite(gpio_led6_offset, (value / 32) % 2);
        RegisterWrite(gpio_led7_offset, (value / 64) % 2);
        RegisterWrite(gpio_led8_offset, (value / 128) % 2);
    }
	
    //get the pushed button values and return it
    int PushButtonGet() {
        if (RegisterRead(gpio_pbtnl_offset))
            return 1;
        if (RegisterRead(gpio_pbtnr_offset))
            return 2;
        if (RegisterRead(gpio_pbtnu_offset))
            return 3;
        if (RegisterRead(gpio_pbtnd_offset))
            return 4;
        if (RegisterRead(gpio_pbtnc_offset))
            return 5;
        return 0;
    }
	
    //turn values of the swicthes to an integer value and return it
    int switchtoInteger()
    {
        return RegisterRead(gpio_sw1_offset) * 1
               + RegisterRead(gpio_sw2_offset) * 2
               + RegisterRead(gpio_sw3_offset) * 4
               + RegisterRead(gpio_sw4_offset) * 8
               + RegisterRead(gpio_sw5_offset) * 16
               + RegisterRead(gpio_sw6_offset) * 32
               + RegisterRead(gpio_sw7_offset) * 64
               + RegisterRead(gpio_sw8_offset) * 128;
    }
};


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