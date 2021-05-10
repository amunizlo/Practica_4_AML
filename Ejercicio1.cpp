#include <Arduino.h>

void anotherTask(void* parameter){
  for(;;){
    Serial.println("This is another Task");
    delay(1000);
  }
  vTaskDelete(NULL);
}

void setup(){
  Serial.begin(115200);
  xTaskCreate(anotherTask, "another Task", 10000, NULL, 1, NULL);
}

void loop(){
  Serial.println("This is ESP32 Task");
  delay(1000);
}