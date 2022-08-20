# remote-shutdown

quickly shutdown, control machineries from a distance

control actuation of electro-pneumatics cylinderand relays 

this project has been designed in other to reduce the risk of late shutdown or easily carry out task from the office.

## wiring schematics

![schematics](https://user-images.githubusercontent.com/65239245/185728107-887e7711-22ef-400d-806f-d4b48cc23d65.png)

### Note
- Always check the datasheet for the required voltage on the rx and tx pin of the bluethoth module in other to avoid frying up the chip 

- If your module makes use of 3.3v for the rs and tx pin, then make use of a voltage divider before powering it up
## Shematics explanation
| pin | use |
| :----: | :----: |
| pin 5 | turn a relay on and off |
```
  