#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
// El cable de datos se conecta al pin 2 del Arduino
#define ONE_WIRE_BUS 16
// Definir una instancia de OneWire para comunicarse
// con cualquier dispositivo OneWire
OneWire oneWire(ONE_WIRE_BUS);
// Pasar la referencia a OneWire del
// Sensor de temperatura Dallas
DallasTemperature sensors(&oneWire);
void setup(void)
{
 // inicia el puerto serie
 Serial.begin(9600);
 Serial.println("Demo de la biblioteca de control del chip de temperatura Dallas");
 // Iniciar la biblioteca
 sensors.begin(); // Establece valor por defecto del chip 9 bit. Si tiene problemas pruebe aumentar
}
void loop(void)
{
  sensors.begin();
 // llamar a sensors.requestTemperatures() para emitir
 // un pedido de temperatura global a todos los que esten en el bus
 sensors.requestTemperatures();  // Enviar el comando para obtener la temperatura
 Serial.print("La temperatura en el dispositivo 1 es: ");
 Serial.println(sensors.getTempCByIndex(0)); 
 // uso de getTempCByIndex para obtener mas datos
}