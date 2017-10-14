#ifndef SENSOR_H
#define SENSOR_H
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


class Sensor{
  public:
    Sensor();
    Sensor(int temp1, int hum1);
    int get_temp();
    int get_humi();
    int view_sensor(); 
  private:
    int temperature;
    int humidity;
    Sensor *next;
};

Sensor::Sensor()
{
  Serial.println("Sensorito!");
  this->temperature = 0;
  this->humidity = 0;
}

Sensor::Sensor(int temp1, int hum1)
{
  this->temperature = temp1;
  this->humidity = hum1;
}

Sensor:: get_temp()
{
  return temperature;
}

Sensor:: get_humi()
{
  return humidity;
}
Sensor:: view_sensor()
{
  lcd.setCursor(1,0);
  lcd.print("T: ");
  lcd.print(temperature, DEC);
  lcd.print(" H: ");
  lcd.print(humidity, DEC);
}
#endif
