#include <SoftwareSerial.h>

SoftwareSerial customSerial(3,4);

int electricMotor = 5;
int state = 0;
void setup() {
  pinMode (electricMotor, OUTPUT);
  digitalWrite(electricMotor,LOW);
  Serial.begin(9600);

}

void loop() {
  if (customSerial.available()>0){
    state = customSerial.read();
  }
  if (state == '0'){
    digitalWrite(electricMotor,LOW);
    Serial.println('off');
    state=0; 
  }
  else if (state =='1'){
    digitalWrite(electricMotor,HIGH);
    Serial.println('off');
    state = 0;
  }
}