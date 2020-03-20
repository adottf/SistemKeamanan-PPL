#include <Key.h>
#include <Keypad.h>
 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // alamat lcd 0x27 (16 char 2baris)
//servo
#include <Servo.h>
Servo myservo;

byte buzzer=A1;
byte led=A0;
unsigned long duration;
unsigned int distance;
 
const byte numRows= 4;
 
const byte numCols= 4;
 
char keymap[numRows][numCols]= 
{ 
{'1', '2', '3', 'A'},
 
{'4', '5', '6', 'B'},
 
{'7', '8', '9', 'C'},
 
{'*', '0', '#', 'D'} };
 
byte rowPins[numRows] = {13,12,11,10}; //Rows 0 to 3
 
byte colPins[numCols]= {8,7,6,5}; //Columns 0 to 3
 
//initializes an instance of the Keypad class
 
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
String ps = "";
void setup() {
  lcd.backlight();
  pinMode(buzzer, OUTPUT);
  pinMode(led,OUTPUT);
 
 //pad
 lcd.init();                      // inisialisasi lcd 
 lcd.init();
 Serial.begin(9600);
 lcd.begin(16, 1);
 lcd.setCursor(0,0);
 lcd.print(" welcome        Input Password");
//servo
 Serial.begin(9600);
 myservo.attach(4);
}
 
 
//If key is pressed, this key is stored in 'keypressed' variable //If key is not equal to 'NO_KEY', then this key is printed out //if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
//==========================variable global===========================
String pass = "", Tpassword = "1234";
byte gagal = 0;
byte i=1;
boolean bX = false, cPass = false, rPass= false;
byte aa = 0;
 
//----------------------------LOOP-------------------------------------
void loop() {
 
  for(i; i<16; i++){
    lcd.scrollDisplayLeft();
    delay(1);
  }
 
 
char keypressed = myKeypad.getKey();
 
if (keypressed != NO_KEY &&  keypressed != 'B' && keypressed != 'D' && keypressed != 'A' && keypressed != 'C' && !cPass)
{
 
  if(i==16){
    lcd.clear();
    ps="";
    lcd.setCursor(0,0);
    lcd.print(" Input Password");
    i=19;
    }
    lcd.setCursor(0, 1);
    ps = ps+keypressed;
    lcd.print(ps); 
}
 
 
 
if(cPass){
    if(rPass) {
      if(keypressed == 'D'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Password Terupdate");
        lcd.setCursor(0,1);
        lcd.print(pass);
        Tpassword = pass;
        rPass = false;
        cPass = false;
        pass = "";
      } else if(keypressed != NO_KEY){
        pass = pass + keypressed;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Password Baru");
        lcd.setCursor(0,1);
        lcd.print(pass);
      }
    }
    else if(keypressed == 'D'){
    lcd.clear();
    lcd.setCursor(0,0);
      if(pass == Tpassword) {
        lcd.print("Password Baru");
        gagal = 0;
        rPass = true;
        pass = "";
      } else {
        if(gagal > 1){
        gagal=0;
        //kirim telegram
        lcd.print("      KAMU     ");
        lcd.setCursor(0,1);
        lcd.print("    HEANG     ");
        Serial.println("kirim");
 
        for(aa=0; aa<10; aa++) {
        digitalWrite(buzzer, HIGH);
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(buzzer,LOW);
        digitalWrite(led, LOW);
        delay(400);
        }
        lcd.clear();
        lcd.print("Input Password");
        rPass = false;
        cPass = false;
      } else {
        lcd.print("   INCORRECT     ");
        digitalWrite(buzzer,HIGH);
        delay(500);
        digitalWrite(buzzer,LOW);
        delay(500);
        lcd.clear();
        lcd.print("Password Lama");
        gagal += 1; 
        rPass = false;
      }
     }
    pass = ""; 
    } else if(keypressed != NO_KEY) {
        pass = pass + keypressed;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Password Lama");
        lcd.setCursor(0,1);
        lcd.print(pass);
     }
  } else if(keypressed=='C'){
  bX = false;
  lcd.clear();
  ps="";
  lcd.setCursor(0,0);
  lcd.print(" Input Password");
} else if(keypressed=='D'){
  lcd.clear();
  lcd.setCursor(0,0);
  
  if(ps == Tpassword) {
    lcd.print("     SUCCESS     ");
    //cek Password untuk buka
    
    gagal = 0;
 
    //servo buka kunci
    //myservo.write(80);
    delay(1000);
    myservo.write(180);
    delay(1000);
    //servo buka pintu
    //myservo1.write(80);
    //delay(1000);
    delay(200);
    //cek objek sekitar dgn infrared
    bX = true;
 
  } else {
    if(gagal > 1){
      gagal=0;
      //kirim telegram
      lcd.print("      GAGAL     ");
      lcd.setCursor(0,1);
      lcd.print("     MALING     ");
      Serial.println("kirim");
      for(aa=0; aa<10; aa++) {
        digitalWrite(buzzer, HIGH);
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(buzzer,LOW);
        digitalWrite(led, LOW);
        delay(400);
        }
      lcd.clear();
      lcd.print("Input Password");
    } else {
      lcd.print("   INCORRECT     ");
      digitalWrite(buzzer,HIGH);
      delay(500);
      digitalWrite(buzzer,LOW);
      delay(500);
      lcd.clear();
      lcd.print("Input Password");
      gagal += 1;
 
    }
  }
  ps = "";
}//buat yang b (tutup)
 else if(keypressed == 'B'){
  delay(100);
  myservo.write(0);
 }
 
if(keypressed == 'A' && !cPass){
    cPass = true;
    lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Password Lama");
      lcd.setCursor(0,1);
      lcd.print(pass);
}
}


