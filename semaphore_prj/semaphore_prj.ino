///////////////////////////////
// TIME VARIABLES

// time that the green light stays on after button has been pressed
int delayTraficGreen = 5000;

// time that led stays on when blinking
int delayBlinkOn = 250;

// time that led stays off when blinking
int delayBlinkOff = 250;

// number of times trafic green light blinks before color changes to yellow
int noTraficGreenBlinks = 3;

// number of times trafic yellow light blinks before color changes to red
int noTraficYellowBlinks = 5;

// number of times trafic red light blinks before color changes to green
int noTraficRedBlinks = 5;

// time that walk light stays red before changing to green
int delayWalkRed = 750;

// time that walk light stays green
int delayWalkGreen = 3000;

// number of times walk green light blinks before color changes to red
int noWalkGreenBlinks = 5;

///////////////////////////////

int traficGreenLed = 5;
int traficYellowLed = 6;
int traficRedLed = 7;

int buttonPin = A1; 
bool buttonPressed = false;

int walkGreenLed = 2;
int walkRedLed = 3;

void setInitialState(){
  digitalWrite(traficGreenLed, HIGH);
  digitalWrite(traficYellowLed, LOW);
  digitalWrite(traficRedLed, LOW);
  
  digitalWrite(walkGreenLed, LOW);
  digitalWrite(walkRedLed, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(traficGreenLed, OUTPUT);
  pinMode(traficYellowLed, OUTPUT);
  pinMode(traficRedLed, OUTPUT);

  pinMode(buttonPin, INPUT);

  pinMode(walkGreenLed, OUTPUT);
  pinMode(walkRedLed, OUTPUT);

  Serial.begin(9600);
  Serial.println("System online");

  setInitialState();
}

void blinkLed(int ledPin, int delayOn, int delayOff, int noBlinks){
  for(int i=0; i<noBlinks; i++){
    digitalWrite(ledPin, HIGH);
    delay(delayOn);
    digitalWrite(ledPin, LOW);
    delay(delayOff);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonRead = digitalRead(buttonPin);
  if(buttonRead == HIGH){
    buttonPressed = true;
  } else {
    buttonPressed = false;
  }

  if(buttonPressed == true){
    Serial.println("Semaphore light change has begun.");
    // Trafic color change from green to yellow to red
    delay(delayTraficGreen);
    blinkLed(traficGreenLed, delayBlinkOn, delayBlinkOff, noTraficGreenBlinks);
    digitalWrite(traficGreenLed, LOW);
    blinkLed(traficYellowLed, delayBlinkOn, delayBlinkOff, noTraficYellowBlinks);
    digitalWrite(traficYellowLed, LOW);
    digitalWrite(traficRedLed, HIGH);


    // Walk color change from red to green
    delay(delayWalkRed);
    digitalWrite(walkRedLed, LOW);
    digitalWrite(walkGreenLed, HIGH);

    // walk color change from green to red
    delay(delayWalkGreen);
    blinkLed(walkGreenLed, delayBlinkOn, delayBlinkOff, noWalkGreenBlinks);
    digitalWrite(walkGreenLed, LOW);
    digitalWrite(walkRedLed, HIGH);

    // blink trafic red light before turning to green
    blinkLed(traficRedLed, delayBlinkOn, delayBlinkOff, noTraficRedBlinks);

    // set leds to initial state (trafic green on - walk red off)
    setInitialState();
    Serial.println("Semaphore back to initial state.");
    buttonPressed = false;
  }
}
