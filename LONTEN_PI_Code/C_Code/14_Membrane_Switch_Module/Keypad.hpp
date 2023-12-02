

#ifndef KEYPAD_H
#define KEYPAD_H

#include "Key.hpp"
#include <wiringPi.h>
#include <stdio.h>

//#define NULL 			'\0'
#define INPUT_PULLUP	0x02
#define bitWrite(x,n,b)	(b ? (x |= 1<<n) : (x &= ~(1<<n)))
#define bitRead(x,n)	((((x>>n)&1) == 1) ? 1 : 0)

#define OPEN LOW
#define CLOSED HIGH

typedef char KeypadEvent;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef struct {
    byte rows;
    byte columns;
} KeypadSize;

#define LIST_MAX 10		// Max number of keys on the active list.
#define MAPSIZE 10		// MAPSIZE is the number of rows (times 16 columns)
#define makeKeymap(x) ((char*)x)


class Keypad : public Key {
public:

	Keypad(char *userKeymap, byte *row, byte *col, byte numRows, byte numCols);

	uint bitMap[MAPSIZE];	// 10 row x 16 column array of bits. Except Due which has 32 columns.
	Key key[LIST_MAX];
	unsigned long holdTimer;

	char getKey();
	bool getKeys();
	KeyState getState();
	void begin(char *userKeymap);
	bool isPressed(char keyChar);
	void setDebounceTime(uint);
	void setHoldTime(uint);
	void addEventListener(void (*listener)(char));
	int findInList(char keyChar);
	int findInList(int keyCode);
	char waitForKey();
	bool keyStateChanged();
	byte numKeys();

private:
	unsigned long startTime;
	char *keymap;
    byte *rowPins;
    byte *columnPins;
	KeypadSize sizeKpd;
	uint debounceTime;
	uint holdTime;
	bool single_key;

	void scanKeys();
	bool updateList();
	void nextKeyState(byte n, boolean button);
	void transitionTo(byte n, KeyState nextState);
	void (*keypadEventListener)(char);
};

//#define __PIN_MODE__PINWRITE__PINREAD__
void pin_mode(byte pinNum, byte mode);
void pin_write(byte pinNum, boolean level);
int  pin_read(byte pinNum); 
#endif


