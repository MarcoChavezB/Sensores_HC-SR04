#include <Arduino.h>
int sensores[3][4] = {{13, 12, 14, 27}, {15, 2, 4, 5}};
int cantSensores = 2;
int cantPinSensor = 4;
long distancia;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < cantSensores; i++){
    for(int j = 0; j < cantPinSensor; j++){
      pinMode(sensores[i][j], OUTPUT);
    }
  }
}

void loop() {
  calcularDistancia();
  delay(1000);
}

void calcularDistancia(){
 for(int i = 0; i < cantSensores; i++){
    for(int j = 0; j < cantPinSensor; j++){
      long duracion = pulseIn(j, HIGH);
      distancia = duracion / 58;
      Serial.println(distancia);
    }
  } 
}