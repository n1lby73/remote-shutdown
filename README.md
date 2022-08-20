# remote-shutdown

Quickly shutdown, control machineries from a distance

control actuation of electro-pneumatics cylinderand relays 

this project has been designed in other to reduce the risk of late shutdown or easily carry out task from the office using bluetooth technology and micro controllers

## wiring schematics

![schematics](https://user-images.githubusercontent.com/65239245/185728107-887e7711-22ef-400d-806f-d4b48cc23d65.png)

### Note
- Always check the datasheet for the required voltage on the rx and tx pin of the bluethoth module in other to avoid frying up the chip 

- If your module makes use of 3.3v for the RS and TX pin, then make use of a voltage divider before powering it up

## pin use
| Arduino pin | use |
| :----: | :----: |
| pin 3 | custom RX pin |
| pin 4 | custom TX pin |
| pin 5 | turn a relay on and off |

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

For more documentation on the library check [Arduino official website](https://docs.arduino.cc/learn/built-in-libraries/software-serial)

```

int electricMotor = 5;
```
- Denotes arduino pin (5) used to control relay where machineries are connected to

```
int receivedData = 0;
```

- Declared a variable to store the data received from the bluethoth
