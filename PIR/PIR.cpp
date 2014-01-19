#include <PIR.h>

/* PIR Contstructor
	This is the constructor for the PIR class. The data pin and
	power pin are denoted here by the user. The boolean values
	are also reset to false here to give a common base.
*/
PIR::PIR(uint8_t dataPin, uint8_t powerPin){
	m_dataPin  = dataPin;
	m_powerPin = powerPin;
	m_isEnabled= false;
	m_isStarted= false;
}

/* PIR Init method
	This is the initalizing method of the PIR class. Here, the
	data pin is setup, and the power pin, if used, is configured
	The timer will also begin counting to ensure it works.
	This is a boolean method and returns true only if
	the control pin was defined by the user.

*/
boolean PIR::Init(){
	if(200 > m_powerPin){
		pinMode(m_powerPin,OUTPUT);
		digitalWrite(m_powerPin, LOW);
		m_isStarted = false;
		m_powerOnTime.Begin();
		return true;
	}else{
		m_isStarted = true;
		return false;
	}
	pinMode(m_dataPin, INPUT);
}

/* PIR Set method
	This is the controlling method of the PIR class. Here, the
	PIR can be turned on and off. The state of the PIR will be denoted
	by the boolean value fed to this method, true being enabled. If
	the user defined a control pin, this method will also power on the
	PIR sensor and start a timer to wait until it can register correct values.
*/
boolean PIR::Set(boolean isEnabled){
	if(200 > m_powerPin){
		digitalWrite(m_powerPin,isEnabled);
		if(isEnabled){
			m_isStarted = false;
			m_powerOnTime.Reset();
		}
	}
	m_isEnabled = isEnabled;
}

boolean PIR::Get(){
	if(m_isEnabled){
		if(!m_isStarted){
			m_isStarted = m_powerOnTime.HasPeriodPassed(5000);
			return false;
		}else{
			return digitalRead(m_dataPin);
		}
	}else{
		return false;
	}
}

