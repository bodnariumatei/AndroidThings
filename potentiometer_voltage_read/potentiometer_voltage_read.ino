int oneKPM_pin = A1;
int tenKPM_pin = A3;
int twentyKPM_pin = A5;

int oneK_value = 0;
int tenK_value = 0;
int twentyK_value = 0;

int greenPin = 11;
int yellowPin = 6;
int redPin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(oneKPM_pin, INPUT);
  pinMode(tenKPM_pin, INPUT);
  pinMode(twentyKPM_pin, INPUT);

  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  oneK_value = analogRead(oneKPM_pin);
  tenK_value = analogRead(tenKPM_pin);
  twentyK_value = analogRead(twentyKPM_pin);

  analogWrite(greenPin, oneK_value / 4);
  analogWrite(yellowPin, tenK_value / 4);
  analogWrite(redPin, twentyK_value / 4);

  Serial.print("Read values: 1K - ");
  Serial.print(oneK_value);
  Serial.print(" | 10K - ");
  Serial.print(tenK_value);
  Serial.print(" | 20K - ");
  Serial.print(twentyK_value);

  float oneK_voltage = (5./1024.)*oneK_value;
  float tenK_voltage = (5./1024.)*tenK_value;
  float twentyK_voltage = (5./1024.)*twentyK_value;
  Serial.print("\tVoltages: 1K - ");
  Serial.print(oneK_voltage);
  Serial.print(" | 10K - ");
  Serial.print(tenK_voltage);
  Serial.print(" | 20K - ");
  Serial.println(twentyK_voltage);
}
