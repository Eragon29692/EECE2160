#ifndef WIIMOTEBTNS_H
#define WIIMOTEBTNS_H

//WiimoteBtns class
class WiimoteBtns {
private:
    //file descriptor
    int fd;
public:
    //contructor
    WiimoteBtns();
    //destructor
    ~WiimoteBtns();
    //Listenning to the event
    void Listen();
    //what to do when the event is read
    void ButtonEvent(int code, int value);
};

#endif

