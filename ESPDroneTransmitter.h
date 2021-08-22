/*
  ESPDroneTransmitter.h - Library for RF24 Transmitter.
  Created by Harit Krishan, August 22, 2021.
  Released into the public domain.
*/

#ifndef ESPDroneTransmitter_h
#define ESPDroneTransmitter_h
#define POT A6

#include "Arduino.h"
#include <SPI.h>
#include "nRF24L01.h"
#include <RF24.h>

class ESPDroneTransmitter {
  public:
    ESPDroneTransmitter();
    ESPDroneTransmitter(int ce, int csn);
    void initTransmitter();
    void setChannel(int channel, int pin);
    void transmit();
    void printStep(char* msg);
    int getStep();
    void incrementStep();
    char* getBytes();

  private:
    RF24 *radio;
    char address[6] = "00001";
    char bytes_to_send[32];
    int channel1, channel2, channel3, channel4;
    int channel1Pin, channel2Pin, channel3Pin, channel4Pin;
    String buffer;
    int stp;

};

#endif
