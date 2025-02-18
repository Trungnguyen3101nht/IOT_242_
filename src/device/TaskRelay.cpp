#include "TaskRelay.h"

void TaskRelayControl(void *pvParameters) {
    // Initialize the relay module
    
}

void TaskRelay_init() {
    xTaskCreate(TaskRelayControl, "TaskRelayControl", 4096, NULL, 2, NULL);
}