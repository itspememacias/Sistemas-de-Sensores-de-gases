 //MEDIDOR DE CONTAMINACION AMBIENTAL BASADO EN ARDUINO MAS JAVA

//Hecho por:  JAVIER RIVADENEIRA Y JAVIER MACIAS
//FECHA:28 DE FEBRERO DEL 2016
//CREADO EN EL EVENTO HACKATHON MANTA 2016
//ESTE CODIGO ES DE DOMINIO PUBLICO


#include <DHT11.h>

double sensorPin0=A0;
double sensorValue0='A';
int sensorPin1=A1;
int sensorValue1='B';
int sensorPin2=A2;
int sensorValue2='C';
float sensorValue3='D'; 
float sensorValue4='E';

int pin=2;
DHT11 dht11(pin);

boolean Key = false;
int mensaje=0;

void setup() {
 
  Serial.begin(9600);}
  

void loop(){
  if (Serial.available()>0){
    mensaje=Serial.read();
  if (mensaje=='1'){
      Key=true;
}
  else{
      Key=false;
      }    
}
if(Key==true){
int err;
float temp, hum;
if ((err=dht11.read(hum, temp))==0)
{
  sensorValue3 = temp;
  sensorValue4 = hum;  
}
 sensorValue0 = analogRead(sensorPin0);
 sensorValue1 = analogRead(sensorPin1);
 sensorValue2 =analogRead(sensorPin2);
 Serial.println(sensorValue0);
 Serial.println(sensorValue1);
 Serial.println(sensorValue2);
 Serial.println(sensorValue3);
 Serial.println(sensorValue4);
 delay(500);
}
}
