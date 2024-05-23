#include <IRremote.h>
#include "remote_buttons.h"
#include "pitches.h"

int remotePin = 3;
IRrecv IR(remotePin);
decode_results cmd;
String myCom;

int buzzerPin = 8;
// notes in the melody:
int melody[] = {
  REST, REST, REST, NOTE_DS4, 
  NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,   
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, 
  NOTE_E4, REST, REST, NOTE_DS4,
  
  NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_E5,
  NOTE_DS5,   
  NOTE_D5, REST, REST, NOTE_DS4, 
  NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,   
  
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, 
  NOTE_E4, REST,
  REST, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4,   
  NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4
};

int durations[] = {
  2, 4, 8, 8, 
  4, 8, 8, 4, 8, 8,
  8, 8,  8, 8, 8, 8, 8, 8,   
  2, 16, 16, 16, 16, 
  2, 4, 8, 4,
  
  4, 8, 8, 4, 8, 8,
  8, 8,  8, 8, 8, 8, 8, 8,
  1,   
  2, 4, 8, 8, 
  4, 8, 8, 4, 8, 8,
  8, 8,  8, 8, 8, 8, 8, 8,   
  
  2, 16, 16, 16, 16, 
  4, 4,
  4, 8, 8, 8, 8, 8, 8,
  16, 8, 16, 8, 16, 8, 16, 8,   
  16, 16, 16, 16, 16, 2
};

int ledPins[] = {10, 11, 12};
int ledStates[] = {0, 0, 0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IR.enableIRIn();

  pinMode(buzzerPin, OUTPUT);
  for(int i=0;i<3;i++){
    pinMode(ledPins[i], OUTPUT);
    //digitalWrite(ledPins[i],HIGH);
    //delay(500);
    //digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while(IR.decode(&cmd) == 0){}

  Serial.println(cmd.value);
  delay(750);
  IR.resume();

  if(cmd.value == OKB){
    int size = sizeof(durations) / sizeof(int);
    for (int note = 0; note < size; note++) {
      int duration = 1000 / durations[note];
      tone(buzzerPin, melody[note], duration);
      int pauseBetweenNotes = duration * 1.6;
      delay(pauseBetweenNotes);
      noTone(buzzerPin);
    }
  }
  if(cmd.value == BTN1){
    //Serial.println("Red LED button");
    if(ledStates[0] == 0){
      digitalWrite(ledPins[0], HIGH);
      ledStates[0] = 1;
    } else {
      digitalWrite(ledPins[0], LOW);
      ledStates[0] = 0;
    }
  }
  if(cmd.value == BTN2){
    //Serial.println("Yellow LED button");
    if(ledStates[1] == 0){
      digitalWrite(ledPins[1], HIGH);
      ledStates[1] = 1;
    } else {
      digitalWrite(ledPins[1], LOW);
      ledStates[1] = 0;
    }
  }
  if(cmd.value == BTN3){
    //Serial.println("Green LED button");
    if(ledStates[2] == 0){
      digitalWrite(ledPins[2], HIGH);
      ledStates[2] = 1;
    } else {
      digitalWrite(ledPins[2], LOW);
      ledStates[2] = 0;
    }
  }
}
