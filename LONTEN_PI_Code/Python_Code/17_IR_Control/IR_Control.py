#!/usr/bin/python

import pylirc, time
import RPi.GPIO as GPIO


blocking = 0;




def setup():

	GPIO.setmode(GPIO.BCM)

	pylirc.init("pylirc", "./conf", blocking)

def map(x, in_min, in_max, out_min, out_max):
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min


def loop():
	while True:
		s = pylirc.nextcode(1)
		print s
		time.sleep(1)
		while(s):
			for code in s:
				print 'Command: ', code["config"] #For debug: Uncomment this
#				line to see the return value of buttons
			if(not blocking):
				s = pylirc.nextcode(1)
			else:
				s = []

def destroy():

	GPIO.cleanup()
	pylirc.exit()

if __name__ == '__main__':
	try:
		setup()
		loop()
	except KeyboardInterrupt:
		destroy()

