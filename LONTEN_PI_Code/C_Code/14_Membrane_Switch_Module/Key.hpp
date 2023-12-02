
#ifndef KEY_H
#define KEY_H

#include <wiringPi.h>

#define boolean bool
#define byte unsigned char 
#define OPEN LOW
#define CLOSED HIGH

typedef unsigned int uint;
typedef enum{ IDLE, PRESSED, HOLD, RELEASED } KeyState;

const char NO_KEY = '\0';

class Key {
public:
	// members
	char kchar;
	int kcode;
	KeyState kstate;
	boolean stateChanged;

	// methods
	Key();
	Key(char userKeyChar);
	void key_update(char userKeyChar, KeyState userState, boolean userStatus);

private:

};

#endif


