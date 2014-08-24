#include <Wire.h>
#include <RealTimeClockDS1307.h>
#include <SD.h>
File myFile;
#include <EEPROM.h>
#define Display_Clock_Every_N_Seconds 1
#define Display_ShortHelp_Every_N_Seconds 25
#include <SoftwareSerial.h>
SoftwareSerial blue(0,1);//0 RX, 1 TX. y ping
int Pin_echo=6;
int Pin_trig=7;
int adelante_D=8;
int atras_D=9;
int adelante_I=2;
int atras_I=3;
int velocidad=10;
int tempPin = A1; 
//variables
int addr=0;
int minuto_;
int segundo_;
int cm;
int spy;
int w;
int f;
int y;
int d;
int i;
int x;
int xv;
int rv;
int lv;
int vv;
int cordenada;
int cordenada1;
int tempC;
char minuto;
char segundo;
char rec;
char direccionv;
char direccion='F';
char direccion1='R';
char direccion2='L';
char Format[] = "00:00:00";
String formato= "";
void setup(){
  blue.begin(9600);
  Serial.begin(9600);
  pinMode(Pin_trig, OUTPUT);
  pinMode(Pin_echo, INPUT); 
  pinMode(adelante_D,OUTPUT);
  pinMode(atras_D,OUTPUT);
  pinMode(adelante_I,OUTPUT);
  pinMode(atras_I,OUTPUT);
  pinMode(velocidad,OUTPUT); 
  pinMode(4, OUTPUT);
  delay(1000);  
  while (!Serial) {
    ; 
  }
  if (!SD.begin(4)) {
    return;
  }
  myFile = SD.open("wily.txt", FILE_WRITE);
  myFile.close();
}
void loop(){
  while(blue.available()){
    rec=blue.read();   
    control();
  }
}
