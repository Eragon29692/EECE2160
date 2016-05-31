#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include "GPIO.h"



GPIO::GPIO(int number1, int number2)
{
// GPIO device files will follow the format
// /sys/class/gpio/gpio<NR>/value
// <NR> has to be replaced with the actual device number passed as an
// argument to the class constructor.
    char device_name1[128];
    sprintf(device_name1, "/sys/class/gpio/gpio%d/value", number1);
// Open	special device file and store file descriptor in class member.
    fd1 = open(device_name1, O_WRONLY);
    if (fd1 < 0)
    {
        std::cerr << "Cannot open " << device_name1 <<" - forgot sudo? \n";
        exit(1);
    }

    char device_name2[128];
    sprintf(device_name2, "/sys/class/gpio/gpio%d/value", number2);
// Open	special device file and store file descriptor in class member.
    fd2 = open(device_name2, O_WRONLY);
    if (fd2 < 0)
    {
        std::cerr << "Cannot open " << device_name2 <<" - forgot sudo? \n";
        exit(1);
    }
}


GPIO::~GPIO()
{
    // Close open file descriptor
    close(fd1);
    close(fd2);
}


void GPIO::GeneratePWM(int period, int pulse1, int pulse2, int num_periods)
{
    // Generate num_perios of the PWM signal
    for (int i = 0; i < num_periods; i++)
    {
        helpSleep(pulse1, pulse2);
    }
}


void GPIO::GenerateVariablePWM(int period, int first_pulse1, int last_pulse1, int num_periods1, int first_pulse2, int last_pulse2, int num_periods2) {

    int pulse1 = first_pulse1;
    int addPerPulse1 = (last_pulse1 - first_pulse1)/num_periods1;
    int pulse2 = first_pulse2;
    int addPerPulse2 = (last_pulse2 - first_pulse2)/num_periods2;

    // Generate num_perios of the PWM signal
    for (int i = 0; i < num_periods1 || i < num_periods2; i++)
    {
        helpSleep(pulse1, pulse2);
        if (pulse1 < last_pulse1)
            pulse1 += addPerPulse1;
        if (pulse2 < last_pulse2)
            pulse2 += addPerPulse2;
    }
}


void helpSleep(int pulse1, int pulse2) {
    if (pulse1 < pulse2) {
        write(fd1, "1", 1);
        write(fd2, "1", 1);
        usleep(pulse1);
        write(fd1, "0", 1);
        usleep(pulse2 - pulse1);
        write(fd2, "0", 1);
        usleep(period - pulse2);
    } else {
        write(fd2, "1", 1);
        write(fd1, "1", 1);
        usleep(pulse2);
        write(fd2, "0", 1);
        usleep(pulse1 - pulse2);
        write(fd1, "0", 1);
        usleep(period - pulse1);
    }
}