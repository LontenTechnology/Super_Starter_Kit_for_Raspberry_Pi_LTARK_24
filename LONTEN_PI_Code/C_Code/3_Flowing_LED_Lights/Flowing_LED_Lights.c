
#include <wiringPi.h>
#include <stdio.h>

// Turn LED(channel) on
void led_on(int channel){
	digitalWrite(channel, LOW);
}

// Turn LED(channel) off
void led_off(int channel){
	digitalWrite(channel, HIGH);
}

int main(void){
	int i;

	// When initialize wiring failed, print messageto screen
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}
	// Set 8 pins' modes to output
	for(i=0;i<8;i++){       
		pinMode(i, OUTPUT);
	}


	while(1){
		// Turn LED on from left to right
		printf("From left to right.\n");
		for(i=0;i<8;i++){
			led_on(i);
			delay(100);
			led_off(i);
		}
		// Turn LED off from right to left
		printf("From right to left.\n");
		for(i=8;i>=0;i--){
			led_on(i);
			delay(100);
			led_off(i);
		}
	}

	return 0;
}

