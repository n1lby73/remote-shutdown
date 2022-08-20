# remote-shutdown

quickly shutdown, control machineries from a distance

control actuation of electro-pneumatics cylinderand relays 

this project has been designed in other to reduce the risk of late shutdown or easily carry out task from the office.

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

imported a libary that helps us create or turn any of the arduino pins into TX and RX pins

### Reason
the bluetooth module makes use of RX and TX pin to tranfer and receive data from your mobile device to the arduino board, it a good thing we create a custom RX and TX pin with the help of the library as it is not advisable to make use of arduino default RX and TX pin
<!-- Due to the fact that 
the libarary is very useful because with it we don't need to go through the stress of unplugging the tx nd rx pin of the bluetoth module before uploading your sketch. moreover it is not advisable to make use of the default RX and TX pins of the arduino -->

