int ledPins[9] = {2, 3, 4, 5, 6, 7, 8, 9};
int ledValues[9];
int carryLed = 12;
bool carryValue;

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<8;i++){
    pinMode(ledPins[i], OUTPUT);
    ledValues[i] = 0;
  }
}

void transformToBinary(int number){
  for(int i = 0; i < 8; i++){
    ledValues[i] = 0;
  }

  int currentDigit = 0;
  while(number != 0 && currentDigit != 8){
    int r = number % 2;
    number = number / 2;
    ledValues[currentDigit++] = r;
  }

  if(number == 0){
    carryValue = false;
  } else {
    carryValue = true;
  }
}

void lightLEDs(){
  for(int i=0;i<8;i++){
    if(ledValues[i] == 1){
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  if(carryValue){
    digitalWrite(carryLed, HIGH);
  } else {
    digitalWrite(carryLed, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 256 ;i++){
    transformToBinary(i);
    lightLEDs();
    delay(1000);
  }
  transformToBinary(256);
  lightLEDs();
}
