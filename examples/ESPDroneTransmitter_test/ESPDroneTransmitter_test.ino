#include <ESPDroneTransmitter.h>

ESPDroneTransmitter transmitter;

void setup() {
  // put your setup code here, to run once:
  printStep("Transmitter Initialized");
  transmitter.setRadioAddr("17619");
  printStep("Transmitter Address Updated");
  transmitter.initTransmitter();
}

void loop() {
  // put your main code here, to run repeatedly:
  transmitter.transmit();
  delay(50);
}

void printStep(char* msg) {
  if(transmitter.getStep() == 0) {
    Serial.begin(9600);
  }
  Serial.print("\t[");
  Serial.print(transmitter.getStep());
  Serial.print("]\t");
  Serial.println(msg);
  transmitter.incrementStep();
}
