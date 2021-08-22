/*
  ESPDroneTransmitter.cpp - Library for ESP32-based Quadcopter.
  Created by Harit Krishan, August 20, 2021.
  Released into the public domain.
*/

#include "ESPDroneTransmitter.h"
#include "Arduino.h"

ESPDroneTransmitter::ESPDroneTransmitter() {
  stp = 0;
  ESPDroneTransmitter(7,8);
}

ESPDroneTransmitter::ESPDroneTransmitter(int ce, int csn) {
  radio = new RF24(ce,csn);
}



void ESPDroneTransmitter::initTransmitter() {
  radio = new RF24(7,8);
  radio->begin();
  radio->openWritingPipe(atoi(address));
  radio->setPALevel(RF24_PA_MIN);
  radio->stopListening();
  printStep("Transmitter Configured");
}

void ESPDroneTransmitter::setChannel(int channel, int pin) {
  if(channel == 1) {
    channel1Pin = pin;
  } else if (channel == 2) {
    channel2Pin = pin;
  } else if (channel == 3) {
    channel3Pin = pin;
  } else if (channel == 4) {
    channel4Pin = pin;
  }

  printStep("Radio Channels Configured");
}

void ESPDroneTransmitter::transmit() {
  channel1 = analogRead(POT);
  buffer = String(channel1);
  buffer.toCharArray(bytes_to_send, 32);
  radio->write(&bytes_to_send, sizeof(bytes_to_send));
  Serial.println(bytes_to_send);
}

void ESPDroneTransmitter::printStep(char* msg) {
  if(stp == 0) {
    Serial.begin(9600);
  }
  Serial.print("\t[");
  Serial.print(stp);
  Serial.print("]\t");
  Serial.println(msg);
  stp++;
}

int ESPDroneTransmitter::getStep() {
  return stp;
}

void ESPDroneTransmitter::incrementStep() {
  stp++;
}

char* ESPDroneTransmitter::getBytes() {
  return bytes_to_send;
}
