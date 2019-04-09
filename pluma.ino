#include <Servo.h>
int RedLed = 1; 
int GreenLed = 0; 
Servo pluma; 
int botonenter = 2; 
int botonset = 4;
int botonsuma = 3; 
int password = 0; 
int i; 

void setup()
{
  pluma.attach(5); 
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(botonenter, INPUT);
  pinMode(botonset, INPUT);
  pinMode(botonsuma,INPUT);
}

void loop()
{
  principal();
  
}
void set(){
digitalWrite(GreenLed, HIGH);
delay(1000);
digitalWrite(GreenLed, LOW);
delay(1000);
digitalWrite(RedLed, HIGH);
  if(password==0){capturenewpassword();}
  else if(password>0){checkpassword();}
}
void capturenewpassword(){
  int number;
  if(digitalRead(botonsuma)==HIGH){number++;}
  else if(digitalRead(botonset)==HIGH){number = password;}
}
void checkpassword(){
  int number;
  if(digitalRead(botonsuma)==HIGH){number++;}
  else if(digitalRead(botonset)==HIGH){number = i;}
  if(i == password){capturenewpassword();}}
void principal(){
  if(digitalRead(botonset)==HIGH){set();}
  else if(digitalRead(botonsuma)==HIGH){checkpassword();}
  }
