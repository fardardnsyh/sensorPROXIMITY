#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


int ir_pin = 8;
int counter = 0;
int hitObject = false;
const int buzzer = 2;     // inisialisasi buzzer pin pada 2

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(ir_pin,INPUT);
  pinMode(buzzer, OUTPUT);  // Untuk menentukan pin buzzer sebagai output
  
}

void loop() {

   int val = digitalRead(ir_pin);

   if( (val == 0) && (hitObject == false){
        counter++;
        hitObject = true;
        Serial.print("Counter = ");
        Serial.println( counter);
        digitalWrite(buzzer, HIGH); 
        lcd.setCursor(0, 0);
  lcd.print("Counter = ");
  lcd.setCursor(2, 1);
  lcd.print(counter);
  delay(4000);
  }
   
   else if( (val ==1) && (hitObject == true) {
        hitObject = false;
        lcd.setCursor(0, 0);
        digitalWrite(buzzer, LOW); 
  lcd.print("Counter = ");
  lcd.setCursor(1, 1);
  lcd.print(counter);
  delay(2000);
        
   }
}







int e18_sensor = 2;
void setup() {
pinMode (e18_sensor, INPUT);
Serial.begin(9600);
}

void loop() {
int objek = digitalRead(e18_sensor);
Serial.print("Status Objek: ");
Serial.println(objek);
delay(500);
}
