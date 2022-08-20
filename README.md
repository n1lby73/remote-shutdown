# remote-shutdown

Quickly shutdown, control machineries from a distance

control actuation of electro-pneumatics cylinderand relays 

this project has been designed in other to reduce the risk of late shutdown or easily carry out task from the office using bluetooth technology and micro controllers

## Usage

Download the updated [android application](https://play.google.com/store/apps/details?id=com.giumig.apps.bluetoothserialmonitor&gl=US) or [IOS application](https://apps.apple.com/us/app/bluetooth-for-arduino/id1505096526) 

Upload and wire your circuit using the schematics below

![schematics](https://user-images.githubusercontent.com/65239245/185728107-887e7711-22ef-400d-806f-d4b48cc23d65.png)

Open up the app and give all requested permission

Hit the search button

![search button](https://user-images.githubusercontent.com/65239245/185731612-c71a64e4-2d52-4602-a601-2b32297a43c7.jpg)

pair the bluetooth device module with your phone
    - dfault key is 1234 or 0000

selct device name and connect in switch mode

![switch mode](https://user-images.githubusercontent.com/65239245/185731729-d61ef368-8fec-4693-ae7c-2d5396f9289a.jpg)


click on the gear icon at the top right corner of the screen and change the parameter sent over bluetooth

### Note![edit parameters](https://user-images.githubusercontent.com/65239245/185732046-c35bac68-f0d1-488a-ab60-1e8f48005e2e.jpg)

- Always check the datasheet for the required voltage on the rx and tx pin of the bluethoth module in other to avoid frying up the chip 

- If your module makes use of 3.3v for the RS and TX pin, then make use of a voltage divider before powering it up

## pin use
| Arduino pin | use |
| :----: | :----: |
| pin 3 | custom RX pin |
| pin 4 | custom TX pin |
| pin 5 | turn relay on and off |

## code guide

```

#include <SoftwareSerial.h>

```

Imported a libary that helps us create or turn any of the arduino pins into TX and RX pins

### Reason
The bluetooth module makes use of RX and TX pin to tranfer and receive data from your mobile device to the arduino board, It's a good thing we create a custom RX and TX pin with the help of the library as it is not advisable to make use of arduino default RX and TX pin

```
SoftwareSerial customSerial(3,4);
```

- Defined a variable called customSerial
- 3 denotes arduino pin 3 as your custom RX pin
- 4 denotes aruino pin 4 as your custom TX pin

    - For more documentation on the library check [Arduino official website](https://docs.arduino.cc/learn/built-in-libraries/software-serial)

```
int electricMotor = 5;
```
- Denotes arduino pin (5) used to control relay where machineries are connected to

```
int receivedData = 0;
```

- Declared a variable to store the data received from the bluethoth module

```
void setup() {

  pinMode (electricMotor, OUTPUT);
  digitalWrite(electricMotor,LOW);
  Serial.begin(9600);

}
```
- Void setup is where you write programs you want to only run once
- Declared my assigned pin for the electric motor as an output pin
- Forced my relay / machineries to always be off at start up
- Begin serial monitor at the speed [baud rate](https://www.geeksforgeeks.org/baud-rate-and-its-importance/) of 9600
    - useful for  debugging purpose

```
void loop(){
```
- Progams you want to continue running

```
 if (customSerial.available()>0){
    receivedData = customSerial.read();
  }
```
- Check if data has been sent to your module
- if data has been sent assign it to the variable called received data

```
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
```

#### Validating process

- If data received is 0
    - Turn off machineries
    - print a message on the serial moinitor that device is off
    - reassign the received value as 0 for safety reasons

- If data received is 1
    - Turn on machineries
    - print a message on the serial moinitor that device is on
    - reassign the received value as 0 for safety reasons
