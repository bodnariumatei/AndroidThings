int buttonPin = 3;
int potPin = A0;
int greenPin = 5;
int yellowPin = 6;
int redPin = 9;

bool systemState = false;

int minRed = 0;
int maxRed = 511;
int minYellow = 256;
int maxYellow = 767;
int minGreen = 512;
int maxGreen = 1023;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(potPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);

  Serial.println("Press the button.");
}

void loop() {
  // put your main code here, to run repeatedly:
  int read = digitalRead(buttonPin);
  if(read == HIGH){
    systemState = abs(systemState - 1);
    if(systemState == false){
      Serial.println("\nSystem state: OFF");
      delay(150);
    } else {
      Serial.println("\nSystem state: ON");
      delay(1000);
    }
    
  }

  if(systemState == true){
    int potValue = analogRead(potPin);
    Serial.print("Pot Value: ");
    Serial.print(potValue);
    if(potValue >= minRed && potValue <= maxRed){
      int redVal = (potValue - minRed) / 2;
      analogWrite(redPin, redVal);
      Serial.print(" - Red Value: ");
      Serial.print(redVal);
    } else {
      analogWrite(redPin, 0);
    }
    if(potValue >= minYellow && potValue <= maxYellow){
      int yellowVal = (potValue - minYellow) / 2;
      analogWrite(yellowPin, yellowVal);
      Serial.print(" - Yellow Value: ");
      Serial.print(yellowVal);
    } else {
      analogWrite(yellowPin, 0);
    }
    if(potValue >= minGreen && potValue <= maxGreen){
      int greenVal = (potValue - minGreen) / 2;
      analogWrite(greenPin, greenVal);
      Serial.print(" - Green Value: ");
      Serial.print(greenVal);
    } else {
      analogWrite(greenPin, 0);
    }
    Serial.println("");
  } else {
    analogWrite(redPin, 0);
    analogWrite(yellowPin, 0);
    analogWrite(greenPin, 0);
  }
}
