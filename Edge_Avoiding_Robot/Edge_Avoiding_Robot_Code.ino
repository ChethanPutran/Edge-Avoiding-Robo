
#include<AFMotor.h>

#define IR1 A0
#define IR2 A1
#define led 9


AF_DCMotor motor1(1, MOTOR12_1KHZ); //DC motor on M1 with 1KHz pwm
AF_DCMotor motor2(2, MOTOR12_1KHZ); //DC motor on M2 with 1KHz pwm
AF_DCMotor motor3(3, MOTOR34_1KHZ); //DC motor on M3 with 1KHz pwm
AF_DCMotor motor4(4, MOTOR34_1KHZ); //DC motor on M4 with 1KHz pwm


int Speed = 100;

void setup() {
  Serial.begin(9600);      // set up Serial library at 9600 bps
  motor1.setSpeed(Speed); // set the motor1 speed between 0 and 255
  motor2.setSpeed(Speed); //  set the motor2 speed between 0 and 255
  motor3.setSpeed(Speed); // set the motor3 speed between 0 and 255
  motor4.setSpeed(Speed); //set the  motor4 speed between 0 and 255
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  delay(500);  
}

void loop()
{
  int SenrightV = digitalRead(IR1);
  int SenleftV = digitalRead(IR2);
  Serial.print("Sensor 1 value:");
  Serial.print(SenrightV);
  Serial.println("");
  Serial.print("Sensor 2 value:");
  Serial.print(SenleftV);
  
  if (SenrightV == LOW && SenleftV == LOW)
  {
    digitalWrite(led, LOW);
    forward();
  }

  if (SenrightV == HIGH && SenleftV == HIGH)
  {
    digitalWrite(led, HIGH);
    back();
    delay(400);
    right();
    delay(550);
    forward();
    delay(200);
  }
  if (SenrightV == LOW && SenleftV == HIGH)
  {
    digitalWrite(led, HIGH);
    back();
    delay(400);
    right();
    delay(550);
    forward();
    delay(200);
  }
  if (SenrightV == HIGH && SenleftV == LOW)
  {
    digitalWrite(led, HIGH);
    back();
    delay(400);
    left();
    delay(550);
    forward();
    delay(200);
  }

}

void forward()
{
  motor1.setSpeed(150); //Define maximum Speed
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(150); //Define maximum Speed
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(150);//Define maximum Speed
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(150);//Define maximum Speed
  motor4.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(150); //Define maximum Speed
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(150); //Define maximum Speed
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(150); //Define maximum Speed
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(150); //Define maximum Speed
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(200); //Define maximum Speed
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(200); //Define maximum Speed
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(200); //Define maximum Speed
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(200); //Define maximum Speed
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(200); //Define maximum Speed
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(200); //Define maximum Speed
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(200); //Define maximum Speed
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(200); //Define maximum Speed
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
} 
