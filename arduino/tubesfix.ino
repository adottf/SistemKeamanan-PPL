//esp
#include <SoftwareSerial.h>

#include <Key.h>
#include <Keypad.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

 RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27,20,4);  // alamat lcd 0x27 (16 char 2baris)
//servo
#include <Servo.h>
Servo myservo;

//esp
String SSID_WIFI="qwerty";
String SSID_KEY="qwerty123";
String WEB_SERVER="192.168.43.70"; //Host
bool koneksiWifi;   //Simpan status koneksi
String QUERY="/SistemKeamanan-PPL/arduino/insert?logMsg=";   //Kueri
SoftwareSerial myESP(2,3); // RX, TX

bool enable = true;
unsigned int button = 9;
unsigned int time;

bool konekWifi();
bool kirimLog(String pesanLog);  
bool initWifi();
//

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
  //esp
    Serial.begin(9600);
    myESP.begin(9600);
    initWifi();
    koneksiWifi = konekWifi();
    pinMode(button, INPUT_PULLUP);
    
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

  if (! rtc.begin()) {
    Serial.println("RTC TIDAK TERBACA");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//update rtc dari waktu komputer
  }
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
 
  DateTime now = rtc.now();
  char keypressed = myKeypad.getKey();
 
  if (keypressed != NO_KEY &&  keypressed != 'B' && keypressed != 'D' && keypressed != 'A' && keypressed != 'C' && !cPass){
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
        lcd.print("Password Terupdate");  //setting password baru
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
          lcd.print("    TEREKAM     ");
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
    } 
    else if(keypressed != NO_KEY) {
        pass = pass + keypressed;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Password Lama");
        lcd.setCursor(0,1);
        lcd.print(pass);
     }
  } 
  
  else if(keypressed=='C'){
  bX = false;
  lcd.clear();
  ps="";
  lcd.setCursor(0,0);
  lcd.print(" Input Password");
  }
  
  else if(keypressed=='D'){
  lcd.clear();
  lcd.setCursor(0,0);
    if(ps == Tpassword) {
      lcd.print("     SUCCESS     ");
      //cek Password untuk buka
    
      gagal = 0;
 
      //servoz buka kunci
      //myservo.write(80);
      myservo.write(0);
        if(koneksiWifi){
            Serial.println("Mengirim: ");
            Serial.println(String("Sistem Terbuka"));
            kirimLog(String("SISTEM TERBUKA"));
        }else{
          konekWifi();
        }
      delay(1000);
      //servo buka pintu
      //myservo1.write(80);
      //delay(1000);
      delay(200);
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
          if(aa==1){
            if(koneksiWifi){
              Serial.println("Mengirim: ");
              Serial.println(String("ALARM BERBUNYI!!!"));
              kirimLog(String("ALARM BERBUNYI!!!!"));
            }else{
               konekWifi();
            }
          }
        }
        lcd.clear();
        lcd.print("Input Password");
        
        }
        else {
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
  }
  
  //buat yang b (tutup)
  else if(keypressed == 'B'){
  delay(100);
  myservo.write(180);
            if(koneksiWifi){
              Serial.println("Mengirim: ");
              Serial.println(String("ALARM BERBUNYI!!!"));
              kirimLog(String("SISTEM TERKUNCI!!!!"));
            }else{
               konekWifi();
            }
            
  }
  
  if(keypressed == 'A' && !cPass){
    cPass = true;
    lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Password Lama");
      lcd.setCursor(0,1);
      lcd.print(pass);
  }

  if(now.second()==50){
    digitalWrite(buzzer,HIGH);
    
  }else{
      digitalWrite(buzzer,LOW);
  }
//esp
  if(digitalRead(button)==LOW && enable){
        
        if(koneksiWifi){
            Serial.println("Mengirim: ");
            Serial.println(String("sistem digunakan"));
            kirimLog(String("Oke"));
        }else{
          konekWifi();
        }
    
  }
}
//esp
bool konekWifi(){
    Serial.begin(9600);
    //setmode
    myESP.println("AT+CWMODE=1");
    if(myESP.find("OK")){
        Serial.println("CWMODE OK");
        String w = "AT+CWJAP=\"";
        w = w + SSID_WIFI;
        w = w + "\",\"";
        w = w + SSID_KEY;
        w = w + "\"";
        myESP.println(w);
        Serial.println(w);
        myESP.setTimeout(15000);
        if(myESP.find("GOT IP")){
            Serial.println("CWJAP OK");
            myESP.setTimeout(200);
            myESP.println("AT+CIPMUX=0");
            if(myESP.find("OK")){
                Serial.println("CIPMUX OK\n");
                return 1;
            }else{
                Serial.println("CIPMUX NOT OK");
                return 0;
            }
        }else{
            Serial.println("CWJAP NOT OK");
            return 0;
        } 
    }else{
        Serial.println("CWMODE NOT OK");
        return 0;
    }
}

bool kirimLog(String pesanLog){
    pesanLog.replace(" ", "%20");
    Serial.begin(9600);
    myESP.setTimeout(200);
    String con;
    con = "AT+CIPSTART=\"TCP\",\"";
    con = con + WEB_SERVER;
    con = con +"\",80";
    Serial.println(con);
    myESP.println(con);
    myESP.setTimeout(1000);
    if(myESP.find("CONNECT")){
        Serial.println("READY TO GET");
    }else{
        Serial.println("CANNOT OPEN COMMUNICATION");
        return 0;
    }
    String request;
    request = "";
    request.concat("GET ");
    request.concat(QUERY);
    request.concat(pesanLog);
    request.concat(" HTTP/1.1\r\n");
    request.concat("Host: ");
    request.concat(WEB_SERVER);
    request.concat("\r\n\r\n");
    request.concat("Host: ");
    request.concat(WEB_SERVER);
    request.concat("\r\n\r\n");
    
    Serial.println("TCP REQUEST: ");
    Serial.println(request);
    myESP.print("AT+CIPSEND=");
    myESP.println(request.length());

    if(myESP.find(">")){
        myESP.println(request);
        if(myESP.find("SEND OK")){
            Serial.print("HTTP REQ SENT\n\n");
            myESP.println("AT+CIPCLOSE");
            if(myESP.find("CLOSED")){
                return 1;
            }
        }
    }else{
        Serial.println("CANNOT SEND REQUEST");
        return 0;
    }
}

//Pertama kali dijalankan untuk mereset wifi
bool initWifi(){
    myESP.setTimeout(5000);
    myESP.println("AT+RST");
    delay(1000);
}

