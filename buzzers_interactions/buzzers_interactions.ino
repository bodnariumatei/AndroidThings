//// ACTIVE BUZZER

// int myNumber;
// int buzzPin = 9;
// String msg = "Please input your number: ";
// int dt = 2000; // 2 secunde

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   pinMode(buzzPin, OUTPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   Serial.println(msg);
//   while(Serial.available() == 0){}

//   myNumber = Serial.parseInt();
//   if(myNumber > 10){
//     for(int i=0;i<256;i=i+50){
//         analogWrite(buzzPin, i);
//         delay(1000);
//     }
//     // digitalWrite(buzzPin, HIGH);
//     // delay(dt);
//     digitalWrite(buzzPin, LOW);
//   }
// }


// PASSIVE BUZZER
int buzzPin1 = 8;
int buzzPin2 = 7;
int buzzTime1 = 1000;
int buzzTime2 = 500;

void setup(){
  pinMode(buzzPin1, OUTPUT);
  pinMode(buzzPin2, OUTPUT);
}

void loop(){
  for(int i = 50; i<= 2500; i=i+10){
    buzzTime1 = i;
    digitalWrite(buzzPin1, HIGH);
    delayMicroseconds(buzzTime1);
    digitalWrite(buzzPin1, LOW);
    delayMicroseconds(buzzTime1);

    digitalWrite(buzzPin2,HIGH);
    delayMicroseconds(buzzTime2);
    digitalWrite(buzzPin2, LOW);
    delayMicroseconds(buzzTime2);
  }
  
}