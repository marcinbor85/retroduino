# retroduino
Open hardware 8051-based arduino-compatible microcomputer

## Features
- Arduino-mega compatible pinout
- 32kB RAM for data memory
- 32kB RAM for program code
- 32kB EEPROM for non-volatile program code
- build-in bootloader (booting from eeprom and run from ram)
- USB PC connection (fast program code loading to ram)
- external data bus for external peripherals

## PCB
![Alt text](hardware/retroduino-s1/assets/retroduino_full.png?raw=true "Board")

## Project purpose
- "because you can"

## Programming
- recommended SDCC compiler

## Memory layout

### Program bus
- 0x0000-0x2FFF - bootloader memory
- 0x8000-0xFFFF - program code memory
### Data bus
- 0x0000-0x00FF - internal ram
- 0x0100-0x7FFF - external peripherals
- 0x8000-0xFFFF - onboard data memory

## TODO
- external boards with digital and analog input/outputs

