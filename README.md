# retroduino
Open hardware 8051-based arduino-compatible microcomputer

## Features
- Arduino-mega compatible pinout
- AT89S8253 based
- 32kB RAM for data memory
- 32kB RAM for program code
- 32kB EEPROM for non-volatile program code
- build-in bootloader (booting from ROM, copy EEPROM to RAM and run)
- USB PC connection (fast program code loading directly to RAM or to EEPROM)
- external data bus for external peripherals

## PCB
![Alt text](hardware/retroduino-s1/assets/retroduino-s1_full.png?raw=true "Board")

## Electric diagram
![Alt text](hardware/retroduino-s1/assets/retroduino-s1_diagram.png?raw=true "Board")

## Project purpose
- "because you can"

## Programming
- recommended SDCC compiler

## Memory layout

### Program bus
- 0x0000-0x2FFF - internal flash with bootloader
- 0x8000-0xFFFF - external program code memory
### Data bus
- 0x0000-0x00FF - internal ram
- 0x0100-0x7FFF - external peripherals
- 0x8000-0xFFFF - external data memory

## TODO
- external boards with digital and analog input/outputs

