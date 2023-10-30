#include <Arduino.h>

int ultraSonicos[3][4] = {{13, 12, 14, 27}, {26, 25, 33, 32}, {2, 5, 6, 7}};
int cantPin = 4;
int delayTime = 2000;
int ledParpadeo = 0;

String encender = "E";
String parar = "P";

bool sensorIsActive = false;


// mandar informacion por json 
// unidades de medida - nombre - identificador 


void encenderSemaforo(int ultraSonicos[3][3], int tiempoRetardo)
{
  for (int j = 0; j < cantPin; j++)
  {

    for (int i = 0; i < cantPin; i++)
    {
      digitalWrite(ultraSonicos[i][j], HIGH);
    }
    
    delay(tiempoRetardo);
    for (int i = 0; i < cantPin; i++)
    {
      digitalWrite(ultraSonicos[i][j], LOW);
    }
  }
}

void detenerSemaforo()
{
  for (int i = 0; i < cantPin; i++)
  {
    for (int j = 0; j < cantPin; j++)
    {
      digitalWrite(ultraSonicos[i][j], LOW);
      pinMode(ultraSonicos[i][j], INPUT);
      Serial.println("off");
    }
  }
}

void setup()
{
  Serial.begin(9600);
}

void OutputLeds()
{
  for (int i = 0; i < cantPin; i++)
  {
    for (int j = 0; j < cantPin; j++)
    {
      pinMode(ultraSonicos[i][j], OUTPUT);
    }
  }
}

void loop()
{
  if (Serial.available() > 0)
  {
    int consolaRead = Serial.read();
    
    if (consolaRead == encender.charAt(0))
    {

      if (!sensorIsActive)
      {
        sensorIsActive = true;
      }
    }
    else if (consolaRead == parar.charAt(0))
    {
      if (sensorIsActive)
      {
        detenerSemaforo();
        sensorIsActive = false;
      }
    }
  }
}