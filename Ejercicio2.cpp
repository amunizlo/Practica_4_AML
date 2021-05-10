#include <Arduino.h>

SemaphoreHandle_t intSem;

void EncenderLED(void*  parameter){
    for(;;) {
        digitalWrite(LED_BUILTIN, HIGH);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void ApagarLED(void* parameter){
    for(;;){
        digitalWrite(LED_BUILTIN, LOW);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    xTaskCreate(EncenderLED, "LED encendido", 10000, NULL, 2, NULL);
    xTaskCreate(ApagarLED, "LED apagado", 10000, NULL, 2, NULL);
}

void loop(){

}