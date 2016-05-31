#ifndef WIIMOTEACCEL_H
#define WIIMOTEACCEL_H

//class WiimoteAccel
class WiimoteAccel {
private:
    //file descriptor
    int fd;
public:
    //constructor
    WiimoteAccel();
    //destructor
    ~WiimoteAccel();
    //Listenning to the event
    void Listen();
    //what to do when the event is read
    virtual void AccelerationEvent(int code, short value);
};


#endif