#ifndef WIIMOTEACCEL_H
#define WIIMOTEACCEL_H

//WiimoteAccel class
class WiimoteAccel {
private:
    //file descriptor
    int fd;
public:
    //constructor
    WiimoteAccel();
    //destructor
    ~WiimoteAccel();
    //Listenning to the events
    void Listen();
    //what to do when an AccelerationEvent is read
    virtual void AccelerationEvent(int code, short value);
};

#endif
