#include "Sensor.h"
#define SEN_COUNT 4

//States
#define VIEW_S1   1
#define VIEW_S2   2
#define EDIT_T    3
#define SAVE_T    4

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  Sensor *arr = setValues();
  views(arr);
}

Sensor* setValues()
{
    int temp1 = 0;
    int hum1 = 0;
    Sensor *arr_sensor;
    for(int i = 0; i < SEN_COUNT; i++)
    {
      Serial.print("SERIAL ");
      Serial.print(i+1);
      Serial.println("\nIntroduce temperatura: ");
      Serial.flush();
      while(!Serial.available())
      {
        ;
      }
      temp1 = Serial.read();
      Serial.println("Introduce humedad: ");
      Serial.flush();
      while(!Serial.available())
      {
        ;
      }
      hum1 = Serial.read();
      arr_sensor[i] = Sensor(temp1, hum1);
    } 
    return arr_sensor;
}

void views(Sensor *arr)
{
  for(int i = 0; i < 4; i++)
  {
    arr[i].view_sensor();
    delay(5000);
  }
}

void loop() {
  
}
