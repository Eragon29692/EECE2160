#ifndef WIIMOTEACCEL_H
#define WIIMOTEACCEL_H

class WiimoteAccel {
private:
    int fd;
public:
    WiimoteAccel();
    ~WiimoteAccel();
    void Listen();
    virtual void AccelerationEvent(int code, short value);
};

#endif