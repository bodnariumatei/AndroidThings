int l1 = 2;
int l2 = 3;
int l3 = 4;
int l4 = 5;

int buttonPin = 12;
int state = LOW;
int reading;
int pressed = false;
int previous = LOW;

unsigned long time = 0;
unsigned long debounce = 200UL;

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

  // button setup
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = digitalRead(buttonPin);
  if(reading == HIGH && previous == LOW && millis() - time > debounce){
    pressed = true;
    if(state == HIGH){
      state = LOW;
    } else {
      state = HIGH;
    }
    time = millis();
  }
  
  if(pressed == true){
    if(state == HIGH){
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(l3, HIGH);
      digitalWrite(l4, LOW);
    } else {
      digitalWrite(l1,LOW);
      digitalWrite(l2,HIGH);
      digitalWrite(l3,LOW);
      digitalWrite(l4, HIGH); 
    }
  }
  previous = reading;
}
