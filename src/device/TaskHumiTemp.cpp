#include "TaskHumiTemp.h"


void TaskTemperature_Humidity(void *pvParameters){
    DHT20 dht20;
    Wire.begin(GPIO_NUM_11, GPIO_NUM_12);
    dht20.begin();
    while(1){
      Serial.println("Task Temperature and Humidity");
      dht20.read();
      double temperature = dht20.getTemperature();
      double humidity = dht20.getHumidity();
  
      Serial.print("Temp: "); Serial.print(temperature); Serial.print(" *C ");
      Serial.print(" Humi: "); Serial.print(humidity); Serial.print(" %");
      Serial.println();
      
      String data = "{";
      data += "\"temperature\":" + String(dht20.getTemperature()) + ",";
      data += "\"humidity\":" + String(dht20.getHumidity());
      data += "}";

      client.publish("v1/devices/me/telemetry", data.c_str());

      vTaskDelay(5000);
    }
  
  }

void TaskTemperature_Humidity_init()
{
    xTaskCreate(TaskTemperature_Humidity, "TaskTemperature_Humidity", 2048, NULL, 2, NULL);
}