#include <globals.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Device_init();
  Task_init();
}

void loop() {
  // OTA maybe
}