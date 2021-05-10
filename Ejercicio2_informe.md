# Práctica 4.2 Sistemas operativos en tiempo real
###### Andrea Muñiz
<p></p>

## Programa + explicación 

> Declaramos las librerias necesarias

```
#include <Arduino.h>
```

> Declaramos una variable de tipo SemaphoreHandle_t

Esta variable se encargará de controlar el "semáforo".

```
SemaphoreHandle_t intSem;
```

> Función EncenderLED()

Esta función genera un bucle for el cual se encarga de encender el LED y esperar un segundo. Una vez terminado el bucle se elimina la tarea.

```
void EncenderLED(void*  parameter){
    for(;;) {
        digitalWrite(LED_BUILTIN, HIGH);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}
```

> Función ApagarLED()

Esta función hace lo mismo que _EncenderLED()_ pero al contrario, lo apaga. De esta forma se van sucediendo ambas funciónes, una apaga el LED y otra lo enciende.

```
void ApagarLED(void* parameter){
    for(;;){
        digitalWrite(LED_BUILTIN, LOW);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}
```

> Función setup()

Esta función indica en qué pin va a sucede la tarea. A continuación se crea la tarea para encender o apagar el LED.

- __EncenderLED__/__ApagarLED__: Nombre de la función que queremos realizar.
- __LED encendido__/__LED apagado__: Nombre que le damos a la tarea que realizará el microcontrolador.
- __10000__: Tamaño que necesitará la tarea.
- __NULL__: Parámetro que le pasamos a la función de la tarea.
- __2__: prioridad que tiene la tarea sobre las demás.
- __NULL__: Controlador de la tarea.

```
void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    xTaskCreate(EncenderLED, "LED encendido", 10000, NULL, 2, NULL);
    xTaskCreate(ApagarLED, "LED apagado", 10000, NULL, 2, NULL);
}
```

> Función bucle

Esta función la dejamos vacía ya que no la necesitamos.

```
void loop(){

}
```

***

## Resultados de ejecutar el programa

Como resultado de compilar el programa descrito, observamos cómo el led azul del microcontrolador ESP32 se enciende y se apaga. En la carpeta en la que se adjunta este archivo, se encuentra un video de este funcionamiento.