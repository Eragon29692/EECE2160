#include <stdlib.h>
#include "WiimoteAccel.h"
#include "ZedBoard.h"

class WiimoteToLed : public WiimoteAccel {
private:
    ZedBoard *zedB;
public:
    WiimoteToLed(ZedBoard *zedBoard) {
	    zedB = zedBoard;
	}
	
	void AccelerationEvent(int code, short acceleration) {
     
		if (code != 3) {
		    return;
		}
		
		if (acceleration > 100) 
		    acceleration = 100;
		if (acceleration < -100)
		    acceleration = -100;
			
		int numberOfLed = abs(acceleration * 8 / 100);
		int i;
		
		for (i = 0; i < 8; i++) {
		    if (i < numberOfLed)
				zedB->setLed(i, 1);
			else
			    zedB->setLed(i, 0);
		}
        
	}
	
};

int main() {
    ZedBoard zedBoard;
    WiimoteToLed wiiToLed(&zedBoard);
    wiiToLed.Listen();
    return 0;
}

