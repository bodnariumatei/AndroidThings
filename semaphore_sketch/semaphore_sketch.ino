int green_led = 2;
int yellow_led = 3;
int red_led = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(green_led, HIGH);
  delay(5000);
  for(int i=0; i<3; i++) {
    digitalWrite(green_led, LOW);
    delay(100);
    digitalWrite(green_led, HIGH);
    delay(300);
  }
  digitalWrite(green_led, LOW);
  digitalWrite(yellow_led, HIGH);
  delay(500);
  for(int i=0; i<3; i++){
    digitalWrite(yellow_led, LOW);
    delay(200);
    digitalWrite(yellow_led, HIGH);
    delay(500);
  }
  digitalWrite(yellow_led, LOW);
  digitalWrite(red_led, HIGH);
  delay(6000);
  digitalWrite(red_led, LOW);
}
