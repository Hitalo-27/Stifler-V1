//adicionando a biblioteca ultrasonic
#include "Ultrasonic.h"

//Criando objeto Ultrasonic e já definindo as portas
Ultrasonic Ultrasonic(2,3);


long microsec = 0;
float distanciaCM = 0;


//MOTOR A
int PH1 = 4;
int PH2 = 5;


//MOTOR B
int PH3 = 6;
int PH4 = 7;


void setup() {
  Serial.begin(9600);
  pinMode (PH1, OUTPUT);  
  pinMode (PH2, OUTPUT);
  pinMode (PH3, OUTPUT);
  pinMode (PH4, OUTPUT);
}

void loop() {
  
   //Lendo o sensor
   microsec = Ultrasonic.timing();

  //Convertendo a distência em CM
 distanciaCM = Ultrasonic.convert(microsec, Ultrasonic::CM);

  Serial.print(distanciaCM);
  Serial.println(" cm");
  delay(10);

  
  if(distanciaCM > 10){
  digitalWrite(PH1, HIGH);
  digitalWrite(PH2, LOW);
  

  digitalWrite(PH3, HIGH);
  digitalWrite(PH4, LOW); 
  }

  else if(distanciaCM < 10){
  digitalWrite(PH1, LOW);
  digitalWrite(PH2, LOW);
  digitalWrite(PH3, LOW);
  digitalWrite(PH4, LOW);
  delay(700);

  digitalWrite(PH1, LOW);
  digitalWrite(PH2, HIGH);
  digitalWrite(PH3, LOW);
  digitalWrite(PH4, HIGH);
  delay(600);

  digitalWrite(PH1, LOW);
  digitalWrite(PH2, LOW);
  delay(1000);

  digitalWrite(PH3, HIGH);
  digitalWrite(PH4, LOW);
  
  }
}
