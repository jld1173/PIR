#include <PIR.h>

PIR::PIR(uint8_t dataPin, uint8_t powerPin){
	m_dataPin  = dataPin;
	m_powerPin = powerPin;
	m_isEnabled= false;
}

boolean PIR::Init(){
	if(200 != m_powerPin){
		pinMode(m_powerPin,OUTPUT);
		digitalWrite(m_powerPin, LOW);
	}
}

boolean PIR::Set(boolean isEnabled){
	if(200 != m_powerPin){
		digitalWrite(m_powerPin,isEnabled);
	}
	m_isEnabled = isEnabled;
}

boolean PIR::Get(){
	if(!m_isEnabled){
		return false;
	}else{
		return digitalRead(m_dataPin);
	}
}
