#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
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
/**
* Write a 4-byte value at the specified general-purpose I/O location.
*
* @param pBase Base address returned by 'mmap'.
* @parem offset Offset where device is mapped.
* @param value Value to be written.
*/
void RegisterWrite(char *pBase, int offset, int value)
{
    * (int *) (pBase + offset) = value;
}
/**
* Read a 4-byte value from the specified general-purpose I/O location.
*
* @param pBase Base address returned by 'mmap'.
* @param offset Offset where device is mapped.
* @return Value read.
*/
int RegisterRead(char *pBase, int offset)
{
    return * (int *) (pBase + offset);
}
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
char *Initialize(int *fd)
{
    *fd = open( "/dev/mem", O_RDWR);
    return (char *) mmap(
               NULL,
               gpio_size,
               PROT_READ | PROT_WRITE,
               MAP_SHARED,
               *fd,
               gpio_address);
}
/**
* Close general-purpose I/O.
*
* @param pBase Virtual address where I/O was mapped.
* @param fd File descriptor previously returned by 'open'.
*/
void Finalize(char *pBase, int fd)
{
    munmap(pBase, gpio_size);
    close(fd);
}
/**
* Show lower 8 bits of integer value on LEDs
*
* @param pBase Base address of I/O
* @param value Value to show on LEDs
*/
void SetLedNumber(char *pBase, int value)
{
     RegisterWrite(pBase, gpio_led1_offset, value % 2);
     RegisterWrite(pBase, gpio_led2_offset, (value / 2) % 2);
     RegisterWrite(pBase, gpio_led3_offset, (value / 4) % 2);
     RegisterWrite(pBase, gpio_led4_offset, (value / 8) % 2);
     RegisterWrite(pBase, gpio_led5_offset, (value / 16) % 2);
     RegisterWrite(pBase, gpio_led6_offset, (value / 32) % 2);
     RegisterWrite(pBase, gpio_led7_offset, (value / 64) % 2);
     RegisterWrite(pBase, gpio_led8_offset, (value / 128) % 2);
}

void switchToLED(char *pBase) 
{
     RegisterWrite(pBase, gpio_led1_offset, RegisterRead(pBase, gpio_sw1_offset));
     RegisterWrite(pBase, gpio_led2_offset, RegisterRead(pBase, gpio_sw2_offset));
     RegisterWrite(pBase, gpio_led3_offset, RegisterRead(pBase, gpio_sw3_offset));
     RegisterWrite(pBase, gpio_led4_offset, RegisterRead(pBase, gpio_sw4_offset));
     RegisterWrite(pBase, gpio_led5_offset, RegisterRead(pBase, gpio_sw5_offset));
     RegisterWrite(pBase, gpio_led6_offset, RegisterRead(pBase, gpio_sw6_offset));
     RegisterWrite(pBase, gpio_led7_offset, RegisterRead(pBase, gpio_sw7_offset));
     RegisterWrite(pBase, gpio_led8_offset, RegisterRead(pBase, gpio_sw8_offset));
}

int PushButtonGet(char *pBase) {
    if (RegisterRead(pBase, gpio_pbtnl_offset))
	return 1;
    if (RegisterRead(pBase, gpio_pbtnr_offset))
        return 2;
    if (RegisterRead(pBase, gpio_pbtnu_offset))
        return 3;
    if (RegisterRead(pBase, gpio_pbtnd_offset))
        return 4;
    if (RegisterRead(pBase, gpio_pbtnc_offset))
        return 5;  
    return 0;
}

int LedtoInteger(char *pBase)
{
  // int result = 0;

     
	return RegisterRead(pBase, gpio_sw1_offset) * 1
	     + RegisterRead(pBase, gpio_sw2_offset) * 2
             + RegisterRead(pBase, gpio_sw3_offset) * 4
             + RegisterRead(pBase, gpio_sw4_offset) * 8
             + RegisterRead(pBase, gpio_sw5_offset) * 16
             + RegisterRead(pBase, gpio_sw6_offset) * 32
             + RegisterRead(pBase, gpio_sw7_offset) * 64
             + RegisterRead(pBase, gpio_sw8_offset) * 128;

	
}

//Button Function:


int main()
{
// Initialize
    int numberOfLED = 8;
    int fd;
    int value;
    char *pBase = Initialize(&fd);
    int *buttonState = malloc(sizeof(int) * 5);
    int pressedButton = 0;
    int pressed= 0;
// Check error
    if (pBase == MAP_FAILED)
    {
        perror("Mapping I/O memory failed - Did you run with 'sudo'?\n");
        return -1;
    }
    
    //value = LedtoInteger(pBase);
    switchToLED(pBase);
  value = LedtoInteger(pBase);

    while(1) 
    {
	pressedButton = PushButtonGet(pBase);
	//usleep(400000);
	if (pressedButton != pressed) {
	pressed = pressedButton;
	printf("Pressed is: %d", pressed);
	//value = LedtoInteger(pBase);
	switch(pressedButton)
	{
		case 1:
			value=value*2;
			value=value%256;
			printf("%d",value);
			//pressedButton = 0;

			SetLedNumber(pBase,value);
			break;
		case 2:
			value=value/2;
                        printf("%d",value);
			//pressedButton = 0;

			SetLedNumber(pBase,value);
			break;
		case 3:
			value++;
			value = value % 256;
                        printf("%d",value);
			//pressedButton = 0;
	
			SetLedNumber(pBase,value);
			break;
		case 4:
			value--;
			value=value %256;
                        printf("%d",value);
			//pressedButton = 0;
			SetLedNumber(pBase,value);
			break;
		case 5:
			value = LedtoInteger(pBase);
			switchToLED(pBase);
			//pressedButton = 0;

			break;
		default:
			break;
	} 
//	pressedButton = 0;	
	}

    } 



    Finalize(pBase, fd);
    return 0;
}
