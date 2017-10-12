#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//States
#define VIEW_S1   1
#define VIEW_S2   2
#define EDIT_T    3
#define SAVE_T    4

// Declaracion de transiciones de estado
void moveLeft();   //Mover a pantalla anterior
void moveRight();  //Mover a pantalla siguiente

// Clases

class Sensor{
  public:
    Sensor(int temp1, int hum1);   //Contructor
    int get_temp();
    int get_humi();
    int view_sensor(); 
  private:
    int temperature;
    int humidity;
};

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
  lcd.setCursor(0,0);
  lcd.print("T: ");
  lcd.print(temperature);
  lcd.setCursor(0,1);
  lcd.print("H: ");
  lcd.print(humidity);
}

void setup() {
  lcd.begin(16,2);
  Sensor sensor1 = Sensor(50, 87);
  sensor1.view_sensor();
  
}

void loop() {
  
}
