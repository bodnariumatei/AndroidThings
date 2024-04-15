int yellow_led0 = 10;
int red_led1 = 11;
int yellow_led1 = 5;
int yellow_led2 = 6;

int startVal = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellow_led0, OUTPUT);
  pinMode(red_led1, OUTPUT);
  pinMode(yellow_led1, OUTPUT);
  pinMode(yellow_led2, OUTPUT);

  analogWrite(yellow_led0, startVal);
  analogWrite(red_led1, startVal);
  analogWrite(yellow_led1, startVal);
  analogWrite(yellow_led2, startVal);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(yellow_led0, random(0, 67));
  delay(random(0, 100));
  analogWrite(yellow_led1, random(45, 220));
  delay(random(0, 50));
  analogWrite(red_led1, random(1, 34));
  delay(random(0, 100));
  analogWrite(yellow_led2, random(15, 156));
  delay(random(0, 50));
}
