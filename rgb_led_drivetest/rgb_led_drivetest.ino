int redPin = 9;
int greenPin = 10;
int bluePin = 11;


void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 20; i < 256; i = i+10){
    for(int j = 20; j < 256; j = j+10){
      for(int k = 20; k < 256; k = k+10){
        analogWrite(redPin, i);
        analogWrite(greenPin, j);
        analogWrite(bluePin, k);
        delay(350);
        analogWrite(redPin, j);
        analogWrite(greenPin, k);
        analogWrite(bluePin, i);
        delay(350);
        analogWrite(redPin, k);
        analogWrite(greenPin, i);
        analogWrite(bluePin, j);
        delay(350);
      }
    }
  }
}
