#include "TaskLED.h"


void TaskLEDControl(void *pvParameters) {
    pinMode(GPIO_NUM_48, OUTPUT); // Initialize LED pin
    int ledState = 0;
    while(1) {
      
      if (ledState == 0) {
        digitalWrite(GPIO_NUM_48, HIGH); // Turn ON LED
      } else {
        digitalWrite(GPIO_NUM_48, LOW); // Turn OFF LED
      }
      ledState = 1 - ledState;
      vTaskDelay(2000);
    }
  }

  void TaskLED_init()
{
    xTaskCreate(TaskLEDControl, "TaskLed", 4096, NULL, 2, NULL);
}