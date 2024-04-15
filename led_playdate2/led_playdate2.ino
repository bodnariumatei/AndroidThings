int speedInputPin = A1;
int speed;

int l1 = 2;
int l2 = 3;
int l3 = 4;
int l4 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  speed = analogRead(speedInputPin);
  //Serial.println(speed);
  digitalWrite(l1, HIGH);
  delay(speed);
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  delay(speed);
  digitalWrite(l2, LOW);
  digitalWrite(l3, HIGH);
  delay(speed);
  digitalWrite(l3,LOW);
  digitalWrite(l4,HIGH);
  delay(speed);
  digitalWrite(l4, LOW); 
}




