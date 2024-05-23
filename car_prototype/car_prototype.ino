#include <AFMotor.h>
 
//initial motors pin
AF_DCMotor motorRight(1);
AF_DCMotor motorLeft(2);
 
String val;
int speedLeft = 195;
int speedRight = 150;

const int trigPin = 8;
const int echoPin = 9;

String directionFlag = "S";
bool automateFlag = false;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
  if(Serial.available()){
    val = Serial.readString();
     
    Stop(); //initialize with motors stoped
     
    if (val == "F" && automateFlag == false){
      forward();
      directionFlag = "F";
      //Serial.println("Moving F");
    }

    if (val == "B" && automateFlag == false){
      back();
      directionFlag = "B";
      //Serial.println("Moving B");
    }

    if (val == "L" && automateFlag == false){
      left();
      directionFlag = "L";
      //Serial.println("Moving L");
    }

    if (val == "R" && automateFlag == false){
      right();
      directionFlag = "R";
      //Serial.println("Moving R");
    }
    
    if (val == "S"){
      Stop();
      directionFlag = "S";
      automateFlag = false;
      //Serial.println("STOP");
    }

    if(val == "A"){
      automateFlag = true;
      //Serial.println("AUTO: ");
    }
  }

  if(automateFlag == true){
    automate();
  } else {
    float distance = getDistance();
    //Serial.print("Distance: ");
    //Serial.println(distance);
    if(distance < 6.0 && directionFlag == "F"){
      Stop();
    }
  }
}
 
void forward()
{
  motorRight.setSpeed(speedRight); //Define maximum velocity
  motorRight.run(FORWARD); //rotate the motor clockwise
  motorLeft.setSpeed(speedLeft); //Define maximum velocity
  motorLeft.run(FORWARD); //rotate the motor clockwise
  //delay(1000);
  //Stop();
}
 
void back()
{
  motorRight.setSpeed(speedRight); //Define maximum velocity
  motorRight.run(BACKWARD); //rotate the motor anti-clockwise
  motorLeft.setSpeed(speedLeft); //Define maximum velocity
  motorLeft.run(BACKWARD); //rotate the motor anti-clockwise
  //delay(1000);
  //Stop();
}
 
void left()
{
  motorRight.setSpeed(speedRight); //Define maximum velocity
  motorRight.run(FORWARD); //rotate the motor anti-clockwise
  motorLeft.setSpeed(speedLeft); //Define maximum velocity
  motorLeft.run(BACKWARD); //rotate the motor anti-clockwise
  delay(350);
  Stop();
}
 
void right()
{
  motorRight.setSpeed(speedRight); //Define maximum velocity
  motorRight.run(BACKWARD); //rotate the motor clockwise
  motorLeft.setSpeed(speedLeft); //Define maximum velocity
  motorLeft.run(FORWARD); //rotate the motor clockwise
  delay(350);
  Stop();
}
 
void Stop()
{
  motorRight.setSpeed(0); //Define minimum velocity
  motorRight.run(RELEASE); //stop the motor when release the button
  motorLeft.setSpeed(0); //Define minimum velocity
  motorLeft.run(RELEASE); //rotate the motor clockwise
}

float getDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration*.0343)/2;
  return distance;
}

void automate(){
  float distance = getDistance();
  if(distance < 5.5 && directionFlag == "F"){
    Stop();
    back();
    delay(300);
    Stop();
    int dir = random(2);
    if(dir == 0){
      left();
      left();
      //Serial.println("Left");
    } else {
      right();
      right();
      //Serial.println("Right");
    }
    delay(100);
    directionFlag = "S";
  } else {
    forward();
    directionFlag = "F";
    //Serial.println("Moving F");
  }
}