#include <SoftwareSerial.h>

SoftwareSerial customSerial(3,4);

int electricMotor = 5;
int receivedData = 0;
void setup() {
  pinMode (electricMotor, OUTPUT);
  digitalWrite(electricMotor,LOW);
  Serial.begin(9600);

}

void loop() {
  if (customSerial.available()>0){
    receivedData = customSerial.read();
  }
  if (receivedData == '0'){
    digitalWrite(electricMotor,LOW);
    Serial.println('machinery turned off');
    receivedData=0; 
  }
  else if (receivedData =='1'){
    digitalWrite(electricMotor,HIGH);
    Serial.println('machinery turned on');
    receivedData = 0;
  }
}