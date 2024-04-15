int ledPins[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int redLeds[5] = {2, 5, 10, 13};
int yellowLeds[5] = {3, 6, 9, 12};
int greenLeds[5] = {4, 7, 8, 11};
// r y g r y g g y r g y r
int delayOn = 20;
int delayOff = 30;

void setup() {
  // put your setup code here, to run once:
  for(int i =0 ; i<12; i++){
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<12;i++){
    digitalWrite(ledPins[i], HIGH);
    delay(delayOn);
    digitalWrite(ledPins[i], LOW);
    delay(delayOff);
  }

  for(int i=11;i>=0;i--){
    digitalWrite(ledPins[i], HIGH);
    delay(delayOn);
    digitalWrite(ledPins[i], LOW);
    delay(delayOff);
  }
  
  for(int k=1;k<=5;k++){
    for(int j=5,i=6;i<12;i++,j--){
      digitalWrite(ledPins[i], HIGH);
      digitalWrite(ledPins[j], HIGH);
      delay(delayOn);
      digitalWrite(ledPins[i], LOW);
      digitalWrite(ledPins[j], LOW);
      delay(delayOff);
    }
    for(int j=0,i=11;i>=6;i--,j++){
      digitalWrite(ledPins[i], HIGH);
      digitalWrite(ledPins[j], HIGH);
      delay(delayOn);
      digitalWrite(ledPins[i], LOW);
      digitalWrite(ledPins[j], LOW);
      delay(delayOff);
    }
  }

  delayOn *= 2;
  for(int k=1; k<10; k++){
    for(int i = 0 ; i<4; i++){
      digitalWrite(redLeds[i], HIGH);
    }
    delay(delayOn);
    for(int i = 0; i<4; i++){
      digitalWrite(redLeds[i], LOW);
    }
    delay(delayOff);
    for(int i = 0 ; i<4; i++){
      digitalWrite(yellowLeds[i], HIGH);
    }
    delay(delayOn);
    for(int i = 0; i<4; i++){
      digitalWrite(yellowLeds[i], LOW);
    }
    delay(delayOff);
    for(int i = 0 ; i<4; i++){
      digitalWrite(greenLeds[i], HIGH);
    }
    delay(delayOn);
    for(int i = 0; i<4; i++){
      digitalWrite(greenLeds[i], LOW);
    }
    delay(delayOff);
  }
  delayOn /= 2;


  for(int k = 0 ;k <150; k++){
    int led = random(2, 13);
    digitalWrite(led, HIGH);
    delay(20);
    digitalWrite(led, LOW);
    delay(10);
  }
}
