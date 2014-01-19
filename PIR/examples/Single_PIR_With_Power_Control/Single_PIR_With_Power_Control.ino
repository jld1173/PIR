/* Single PIR With Power Control
//
//  This example reads a PIR sensor, while controlling its power.
//  The PIR sensor's data line is wired to pin 3
//  The ground on the PIR sensor is passed through an npn transistor
//  that is controlled by pin 4
//
//  To use this example:
//  * Follow wiring stated above
//  * Upload this code to the board
//  * Open the serial monitor
//  * Send "1" over the serial monitor to turn PIR on and off
//
//  Author:
//  Jordan Duane Jones, Chief Programmer at RedShift Creations
*/
#include <Timer.h>
#include <PIR.h>


PIR examplePIR(3,4);
boolean isOn = false;

void setup(){

  examplePIR.Init(); 
  examplePIR.Set(true);
  Serial.begin(9600);
  Serial.println("Hello World");
}

void loop(){
  if(examplePIR.Get()){
    Serial.println("Movement");

  }else{
  }
  if(Serial.available()){
    if(49 == Serial.read()){
      isOn = !isOn;
      examplePIR.Set(isOn);
    }
  }
  delay(5);
}
