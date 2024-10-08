#include "VNM.h"

VonNeumannMachine vnm;

void setup() {
    Serial.begin(9600);
}

void loop(){
  VonNeumannMachine obj;
  int i = 0;
  char c;
  while(true){ 
  	if(Serial.available() >= 3){
      i++;
      String x((char)Serial.read());
      String y((char)Serial.read());
      String w((char)Serial.read());
      String str = x+y+w;
      Serial.println(str);
  
  		obj.registerOperation(str);
      if(i >= 95){
        obj.operate();
      }
      
      delay(10);
      char c = Serial.read(); // get '\n' or 'space' between expressions, DO NOT REMOVE
	
  	}
  }
}
