#include <PIR.h>

PIR::PIR(uint8_t dataPin, uint8_t powerPin){
	m_dataPin  = dataPin;
	m_powerPin = powerPin;
	m_isEnabled= false;
	m_isStarted= false;
}

boolean PIR::Init(){
	if(200 > m_powerPin){
		pinMode(m_powerPin,OUTPUT);
		digitalWrite(m_powerPin, LOW);
		m_isStarted = false;
		m_powerOnTime.Begin();
	}else{
		m_isStarted = true;
	}
}

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
			m_isStarted = (m_powerOnTime.Get() - 5000) > 0;
			return false;
		}else{
			return digitalRead(m_dataPin);
		}
	}else{
		return false;
	}
}

