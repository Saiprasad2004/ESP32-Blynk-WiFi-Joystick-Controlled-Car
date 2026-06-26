#define BLYNK_TEMPLATE_ID "TMPL3sFbAFbcH"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "6cX7TGgNCvYp5lVD7lO8Q2djvXWdTgk5"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14

#define ENA 33
#define ENB 32

int x = 0;
int y = 0;
int speedValue = 180;

char ssid[] = "moto g57 power_3615";
char pass[] = "hotspot ";

void setup(){

  Serial.begin(115200);

  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT); 
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  ledcAttach(ENA, 5000, 8);
  ledcAttach(ENB, 5000, 8);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);


}

void loop()
{
  Blynk.run();
}

void controlCar()
{
  if(y > 100){ 
    Serial.println("front");
    front();
  }
  else if(y < -100){
    back();
    Serial.println("back");
  }
  else if(x > 100){
    right();
    Serial.println("right");
  }
  else if(x < -100){
    left();
    Serial.println("left");
  }
  else {
    stop();
    Serial.println("stop");
  }
  Serial.print("x:");
  Serial.println(x);
  Serial.print("y:");
  Serial.println(y);
}

BLYNK_WRITE(V2)
{
   x = param.asInt();
  controlCar();
}

BLYNK_WRITE(V3)
{
   y = param.asInt();
  controlCar();
}


BLYNK_WRITE(V4)
{
  speedValue = param.asInt();

  Serial.print("Speed = ");
  Serial.println(speedValue);
}

void front(){
  ledcWrite(ENA,speedValue);
  ledcWrite(ENB,speedValue);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void right(){
  ledcWrite(ENA,250);
  ledcWrite(ENB,250);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void left(){
  ledcWrite(ENA,250);
  ledcWrite(ENB,250);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void back(){
  ledcWrite(ENA,speedValue);
  ledcWrite(ENB,speedValue);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void stop(){
  ledcWrite(ENA,0);
  ledcWrite(ENB,0);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);

}


