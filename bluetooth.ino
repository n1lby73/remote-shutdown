#include <SoftwareSerial.h>

SoftwareSerial customSerial(3,4);

int motor = 7;
int state = 0;
void setup() {
  pinMode (motor, OUTPUT);
  digitalWrite(motor,LOW);
  Serial.begin(9600);

}

void loop() {
  if (customSerial.available()>0){
    state = customSerial.read();
  }
  if (state == '0'){
    digitalWrite(motor,LOW);
    Serial.println('off');
    state=0; 
  }
  else if (state =='1'){
    digitalWrite(motor,HIGH);
    Serial.println('off');
    state = 0;
  }
}