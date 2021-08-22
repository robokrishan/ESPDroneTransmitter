# ESPDroneTransmitter
Library for driving an NRF24L01+ Radio-based Receiver. The ESPDroneTransmitter class is written for the Atmega328P MCU, tested on an Arduino Nano.

The library is for easily configuring and deplying an RC Transmitter object onto an Arduino board.

# Dependencies
Library | Author
------- | ------
<SPI.h> | Internal Arduino Lib
<RF24.h> | J. Coliz, 2011

The transmitter object uses the NRF24L01+ module configured on the SPI Bus. Use the parametrized constructor - RF24(CE,CS). Default configuration is RF24(7,8);

# Hardware
The list of elementary hardware is tabulated below.
Hardware | Description
-------- | -----------
Arduino Nano/Uno | Microcontroller Board for running Transmitter Firmware
NRF24L01+ | 2.4 GHz Wireless Transceiver Module


# Wireless Comms.
The ESPDroneTransmitter object is programmed to read raw digital input from a potentiometer connected to Analog Pin 6 (A6), parse the input into a char array, and transmit to the FC receiver (ESPDrone object). The raw input from the potentiometer is in the range [0,1023].

The ESPDrone library can be found on the following Github Link: https://github.com/robokrishan/ESPDrone
