#ifndef GPIO_H
#define GPIO_H

class GPIO
{
    // File descriptor
    int fd1;
    int fd2;
public:
    /**
    * Class constructor.
    *
    * @param number
    * Port number for GPIO.
    */
    GPIO(int number1, int number2);
    /**
    * Class destructor.
    */
    ~GPIO();
    /**
    * Generate a PWM signal, blocking the caller while the signal is being
    * generated.
    *
    * @param period
    * PWM period in microseconds.
    *
    * @param pulse
    * Duration of the pulse in microseconds.
    *
    * @param num_periods
    * Number of periods to generate.
    */
    void GeneratePWM(int period, int pulse1, int pulse2, int num_periods);

    void GenerateVariablePWM(int period, int first_pulse1, int last_pulse1, int num_periods1, int first_pulse2, int last_pulse2, int num_periods2);

};
#endif
