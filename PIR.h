/* 	PIR.h
// 	Abstract:
// 	This code was written in order to allow a user to control a 
//	passive infrared sensor with ease. This library will allow 
//	the use of a PIR class
//
// 	Within the class the user can:
//	* Declare the pins of the pir sensor
//	* Prepare the micro controllers pins for the sensor
// 	* Read the data out of the PIR sensor
// 	* Disable the PIR sensor:
//		Stop reading sensor
//		Power off sensor
//	
//	Dependencies:
//	* This code has been tested with arduino version 1.0.1
//	* The code functions in arduino versions 1.0.1+
//	* This code has not been tested for compadibility with older
//	versions of the ide
//	* This code assumes the user places a pull down resistor
//	on the data pin of the micro controller to ensure
//	accurate readings
//	* Should the user wish to power the PIR on and off,
//	a transistor must be used to power the PIR to prevent from
//	damaging the mircocontroller.
//
//	Known issues:
//	* When first powered on, the PIR sensor will send a high
//	signal reguardless of the surrounding motion. The code does
//	not currently account for this issue, but in future releases
//	the problem will be removed.
//	* The sensor readings are not 100% accurate while the sensor
//	is not detecting motion. This issue is temporarily fixed by
//	placing a pull down resistor on the data line.
//
//	Assumptions
//	* This code assumes that the user will be using the arduino
//	ide version 1.0.1+, failure to do so, may result in 
//	unpredictable results.
//	* This code assumes that the user will place a pull down
//	resistor on the data read pin.
//	* This code assumes that, should the user use this library
//	to power a PIR sensor on and off, the user will place a
//	resistor between the micro controller and a control
//	transistor
//
//	Author:
//	Jordan Duane Jones, Chief Programmer at RedShift Creations
//	
//	Modification Log:
//	December 7th, 2013 - Initial Release without examples
*/


#ifndef PIR_H
#define PIR_H

#if (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

class PIR{
public:
	PIR(uint8_t dataPin, uint8_t powerPin = 200);
	boolean Set(boolean isEnabled);
	boolean Get();
	boolean Init();

private:
	uint8_t m_dataPin, m_powerPin; 
	boolean m_isEnabled;
	
};

#endif