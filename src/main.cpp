#include <globals.h>

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  Serial.println("Mã số sinh viên: 2014882!");

  // Initialize device and tasks
  Device_init();
  Task_init();
}

void loop() {
  // OTA maybe
}