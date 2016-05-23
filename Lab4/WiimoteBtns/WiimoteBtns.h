#ifndef WIIMOTEBTNS_H
#define WIIMOTEBTNS_H

class WiimoteBtns {
private:
    int fd;
public:
    WiimoteBtns();
    ~WiimoteBtns();
    void Listen();
    void ButtonEvent(int code, int value);
};

#endif
