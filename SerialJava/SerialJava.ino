#include <Ezo_uart.h>
#include <SoftwareSerial.h> 
SoftwareSerial myserial(11,12);
char c;

void setup() {
  
  Serial.begin(38400);
  myserial.begin(9600);
  for (int a = 2; a <= 7; a++){
  pinMode(a, OUTPUT);
  digitalWrite(a, HIGH);}
}


void loop() {
  
    
if (Serial.available() != 0) {    
    char ledControl = Serial.read();
    
    if (ledControl == '0') {
      for (int a = 2; a <= 7; a++){
  digitalWrite(a, HIGH);}}
    
    if (ledControl == '1') {
      digitalWrite(7,LOW);
      delay(500);
      for (int a = 2; a <= 6; a++){
  digitalWrite(a, LOW);
  digitalWrite(7,HIGH);
  if(a > 2) {
    digitalWrite(a-1,HIGH);
  }
  delay(500);
  }
  for (int i = 6; i >= 2; i--){
    digitalWrite(i, LOW);
    if(i < 6) {
    digitalWrite(i+1,HIGH);
  }
  delay(500);
  }
  digitalWrite(2,HIGH);
  digitalWrite(7,LOW);
      delay(500);
      digitalWrite(7,HIGH);
  for (int a = 2; a <= 7; a++){
    digitalWrite(a, LOW);
  }
  delay(400);
  for (int a = 2; a <= 7; a++){
    digitalWrite(a, HIGH);
  }
  delay(400);
  
    for (int a = 2; a <= 7; a++){
    digitalWrite(a, LOW);
  }
  delay(400);
  for (int a = 2; a <= 7; a++){
    digitalWrite(a, HIGH);
  }
  delay(400);
  
    for (int a = 2; a <= 7; a++){
    digitalWrite(a, LOW);
  }
  delay(400);
  for (int a = 2; a <= 7; a++){
    digitalWrite(a, HIGH);
  }
  delay(400);
  for (int a = 2; a <= 7; a++){
    digitalWrite(a, LOW);
  }
  delay(400);
  for (int a = 2; a <= 7; a++){
    digitalWrite(a, HIGH);
  }
  delay(400);
  for (int a = 2; a <= 7; a++){
    digitalWrite(a, LOW);
  }
  delay(400);
  for (int a = 2; a <= 7; a++){
    digitalWrite(a, HIGH);
  }
  delay(400);
  }
  }

if (myserial.available() != 0){
  c = myserial.read();
 
  Serial.print('1121');
  
}

}
