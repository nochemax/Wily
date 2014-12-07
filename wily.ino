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
int duracion;
int cm;
int spy;
int prevCommand;
int w=0;
int f=0;
int y=0;
int d=0;
int i=0;
int x=0;
int xv=0;
int rv=0;
int lv=0;
int vv=0;
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

  if(blue.available()>0){
    prevCommand = rec;
    rec=blue.read();   
    if(rec!=prevCommand){
      switch(rec){
      case 'F'://frente
        ultrasonido();
        analogWrite(velocidad,spy);
        digitalWrite(atras_D,0);
        digitalWrite(atras_I,0);
        digitalWrite(adelante_D,1);
        digitalWrite(adelante_I,1);
        seguimientoF();  
        direccionv=direccion;
        break;
      case 'B'://atras
        analogWrite(velocidad,spy);
        digitalWrite(adelante_D,0);
        digitalWrite(adelante_I,0);
        digitalWrite(atras_D,1);
        digitalWrite(atras_I,1);
        break;
      case 'R'://derecha
        ultrasonido();
        analogWrite(velocidad,spy);
        digitalWrite(adelante_D,0);
        digitalWrite(atras_I,0);
        digitalWrite(adelante_I,1);
        digitalWrite(atras_D,1);
        break;
        seguimientoR();
        direccionv=direccion1;
      case 'L'://izquierada
        ultrasonido();
        analogWrite(velocidad,spy);
        digitalWrite(adelante_I,0);
        digitalWrite(atras_D,0);
        digitalWrite(adelante_D,1);
        digitalWrite(atras_I,1);
        seguimientoL();
        direccionv=direccion2;
        break;
      case 'S'://stop y obteniendo datos 
        digitalWrite(atras_D,0);
        digitalWrite(atras_I,0);
        digitalWrite(adelante_D,0);
        digitalWrite(adelante_I,0);
        break;
      case 'W'://homi casa calculos de trayectoria luces frontal
        while(x<=1){
          calculo();   
          x++;
          y=0; 
        }
        break;   
      case 'U'://borrar memoria para nuevo recorido 
        while(y<=1){
          for ( addr = 0; addr <=10; addr++){
            EEPROM.write(addr, 0);
          } 
          if (addr==11){
            addr = 0;
            RTC.readClock();
            delay(80);  
            minuto=RTC.getMinutes();
            segundo=RTC.getSeconds();
            minuto_ = int(minuto);
            segundo_=int(segundo);
            minuto_=(minuto_+segundo_);
            EEPROM.write(addr,  minuto_);   
            delay(80);
          } 
          y++; 
          x=0; 
        } 
        break;   
      case '1'://velocidad
        spy=25;
        analogWrite(velocidad,spy);
        break;
      case '2':
        spy=51;
        analogWrite(velocidad,spy);
        break;
      case '3':
        spy=76;
        analogWrite(velocidad,spy);
        break;
      case '4':
        spy=102;
        analogWrite(velocidad,spy);
        break;
      case '5':
        spy=127;
        analogWrite(velocidad,spy);
        break;
      case '6':
        spy=153;
        analogWrite(velocidad,spy);
        break;
      case '7':
        spy=178;
        analogWrite(velocidad,spy);
        break;
      case '8':
        spy=204;
        analogWrite(velocidad,spy);
        break;
      case '9':
        spy=229;
        analogWrite(velocidad,spy);
        break;
      case 'q':
        spy=255;
        analogWrite(velocidad,spy);
        break;
      }
    }
  }
  else{
    RTC.readClock();
    RTC.getFormat(Format);
    delay(80);
    formato="";
    tempC=analogRead(tempPin); 
    tempC=(5 * tempC * 100)/1024; 
    formato+=String(Format)+String(".")+String(tempC)+String(".")+String(direccionv)+String(".")+String(cm);
    myFile=SD.open("wily.txt", FILE_WRITE);
    if (SD.exists("wily.txt")){         
      myFile.println(formato);
      myFile.close();          
    }
    ultrasonido();    
  }
}
