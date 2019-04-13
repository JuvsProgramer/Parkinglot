
#include <Servo.h>
int RedLed = 1; 
int GreenLed = 0; 
Servo pluma; 
int botonenter = 2; 
int botonset = 4;
int botonsuma = 3; 
int password = 0; 
int i; 
boolean passwordisright = false; 
int whatisrunning;
int whatisbeingpressed; 
void setup()
{
  pluma.attach(5); 
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(botonenter, INPUT);
  pinMode(botonset, INPUT);
  pinMode(botonsuma,INPUT);
  Serial.begin(9600);
}

void loop()
{
 UX();  
  principal();
  
}
void set(){
 whatisrunning = 2; 
digitalWrite(GreenLed, HIGH);
delay(1000);
digitalWrite(GreenLed, LOW);
delay(1000);
digitalWrite(RedLed, HIGH);
  if(password==0){capturenewpassword();}
  else if(password>0){checkpassword();}
}
void capturenewpassword(){
  whatisrunning = 4;
  int number;
  if(digitalRead(botonsuma)==HIGH){number++;}
  else if(digitalRead(botonset)==HIGH){number = password;}
  digitalWrite(GreenLed, HIGH);
  delay(500);
  digitalWrite(GreenLed, LOW);
  delay(500);
  digitalWrite(GreenLed, HIGH);
  delay(500);
  digitalWrite(GreenLed, LOW);
}
void checkpassword(){
   whatisrunning = 3; 
  int number;
  passwordisright = false; 
  if(digitalRead(botonsuma)==HIGH){number++;}
  else if(digitalRead(botonset)==HIGH){number = i;}
  if(i == password){passwordisright = true;}
  else if(i !== password){passwordisright = false;}
  if(passwordisright == true){pluma.write(90);}
   else if(passwordisright == false){
    pluma.write(0);
    digitalWrite(RedLed, HIGH);
    delay(500);
    digitalWrite(RedLed, LOW);
    }}
    
  
void principal(){
  whatisrunning = 1; 
  if(digitalRead(botonset)==HIGH){set();
  digitalWrite(RedLed, LOW);
  digitalWrite(GreenLed, LOW);
  whatisbeingpressed = 1;}
  else if(digitalRead(botonsuma)==HIGH){checkpassword();
  digitalWrite(RedLed, LOW);
  digitalWrite(GreenLed, LOW);
  whatisbeingpressed = 2; }
  }
void UX(){
  delay(2000);
  Serial.println("-------------------------------");
  Serial.println(whatisrunning); 
  Serial.println(passwordisright);
  Serial.println(password);
  Serial.println(whatisbeingpressed); 
  Serial.println("-------------------------------");
  }
