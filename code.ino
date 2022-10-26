// Escalade Source Code:
// Contributed by : Rohit Roy

#define BLYNK_USE_DIRECT_CONNECT
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp32_BT.h>
#include <Servo.h>
char auth[] = "9-2EcwL6VJX7jsrNGhXwQAOIfkLEjo9-";
Servo gripperServo;
// Servo ropeServo;
int gripperServoPin = 15;

// BASE MOTOR 1
int motor1Pin1 = 4;
int motor1Pin2 = 2;
int motor1SpeedPin = 5;
// BASE MOTOR 2
int motor2Pin1 = 18;
int motor2Pin2 = 19;
int motor2SpeedPin = 14;
// GRIPPER DC MOTOR
int gripperMotorPin1 = 27;
int gripperMotorPin2 = 26;
// CLIMBING MOTOR
int climbingMotor1Pin1 = 33;
int climbingMotor1Pin2 = 32;
int climbingMotor2Pin1 = 23;
int climbingMotor2Pin2 = 22;

// SETTING PWM PROPERTIES
const int freq = 30000;
const int resolution = 8;
const int pwmChannel1 = 0;
const int pwmChannel2 = 1;
int dutycycle = 220;

// Motor controls
void right() {
  // Move the DC motor forward at maximum speed

  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  ledcSetup(pwmChannel1, freq, resolution);
  ledcAttachPin(motor1SpeedPin, pwmChannel1);
  ledcWrite(pwmChannel1, dutycycle);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  ledcSetup(pwmChannel2, freq, resolution);
  ledcAttachPin(motor2SpeedPin, pwmChannel2);
  ledcWrite(pwmChannel2, dutycycle);
}
void left() {
  // Move the DC motor backward at maximum speed
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  ledcSetup(pwmChannel1, freq, resolution);
  ledcAttachPin(motor1SpeedPin, pwmChannel1);
  ledcWrite(pwmChannel1, dutycycle);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  ledcSetup(pwmChannel2, freq, resolution);
  ledcAttachPin(motor2SpeedPin, pwmChannel2);
  ledcWrite(pwmChannel2, dutycycle);
}
void backward() {
  // Move the DC motor left at maximum speed
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  ledcSetup(pwmChannel1, freq, resolution);
  ledcAttachPin(motor1SpeedPin, pwmChannel1);
  ledcWrite(pwmChannel1, dutycycle);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  ledcSetup(pwmChannel2, freq, resolution);
  ledcAttachPin(motor2SpeedPin, pwmChannel2);
  ledcWrite(pwmChannel2, dutycycle);
}
void forward() {
  // Move the DC motor right at maximum speed
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  ledcSetup(pwmChannel1, freq, resolution);

  ledcAttachPin(motor1SpeedPin, pwmChannel1);
  ledcWrite(pwmChannel1, dutycycle);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  ledcSetup(pwmChannel2, freq, resolution);
  ledcAttachPin(motor2SpeedPin, pwmChannel2);
  ledcWrite(pwmChannel2, dutycycle);
}
void dontMove() {
  // Stop the DC motor
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
void up() {
  digitalWrite(climbingMotor1Pin1, HIGH);
  digitalWrite(climbingMotor1Pin2, LOW);
  digitalWrite(climbingMotor2Pin1, LOW);
  digitalWrite(climbingMotor2Pin2, HIGH);
}
void down() {
  digitalWrite(climbingMotor1Pin1, LOW);
  digitalWrite(climbingMotor1Pin2, HIGH);
  digitalWrite(climbingMotor2Pin1, HIGH);
  digitalWrite(climbingMotor2Pin2, LOW);
}
void climbStop() {
  digitalWrite(climbingMotor1Pin1, LOW);
  digitalWrite(climbingMotor1Pin2, LOW);
  digitalWrite(climbingMotor2Pin1, LOW);
  digitalWrite(climbingMotor2Pin2, LOW);
}
void gripperClose() {
  digitalWrite(gripperMotorPin1, HIGH);
  digitalWrite(gripperMotorPin2, LOW);
}
void gripperOpen() {
  digitalWrite(gripperMotorPin1, LOW);
  digitalWrite(gripperMotorPin2, HIGH);
}
void gripperStop() {
  digitalWrite(gripperMotorPin1, LOW);
  digitalWrite(gripperMotorPin2, LOW);
}
void gripperServoUp() {
  gripperServo.attach(gripperServoPin);
  gripperServo.write(0);
}
void gripperServoDown() {
  gripperServo.attach(gripperServoPin);
  gripperServo.write(180);
}
void gripperServoStop() { gripperServo.detach(); }
// BASE MOTOR CONTROL
BLYNK_WRITE(V1) {
  int x = param[0].asInt();
  int y = param[1].asInt();
  if (x == 1 && y == 1) {
    dontMove();
  } else if (x == 2 && y == 1) {
    right();
  } else if (x == 0 && y == 1) {
    left();
  } else if (x == 1 && y == 2) {
    forward();
  } else if (x == 1 && y == 0) {
    backward();
  }
}
// CLIMBING DC MOTOR CONTROL UP
BLYNK_WRITE(V2) {
  if (param.asInt() == 1) {
    up();
  } else {
    climbStop();
  }
}
// CLIMBING DC MOTOR CONTROL DOWN
BLYNK_WRITE(V4) {
  if (param.asInt() == 1) {
    down();
  } else {
    climbStop();
  }
}
// GRIPPER DC MOTOR CONTROL OPEN
BLYNK_WRITE(V3) {
  if (param.asInt() == 1) {
    gripperOpen();
  } else {
    gripperStop();
  }
}
// GRIPPER DC MOTOR CONTROL CLOSE
BLYNK_WRITE(V5) {
  if (param.asInt() == 1) {
    gripperClose();
  } else {
    gripperStop();
  }
}
// GRIPPER SERVO CONTROL UP
BLYNK_WRITE(V6) {
  if (param.asInt() == 1) {
    gripperServoUp();
  } else if (param.asInt() == 0) {
    gripperServoStop();
  }
}
// GRIPPER SERVO CONTROL DOWN
BLYNK_WRITE(V7) {
  if (param.asInt() == 1) {
    gripperServoDown();
  } else if (param.asInt() == 0) {
    gripperServoStop();
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  pinMode(climbingMotor1Pin1, OUTPUT);
  pinMode(climbingMotor1Pin2, OUTPUT);
  pinMode(climbingMotor2Pin1, OUTPUT);
  pinMode(climbingMotor2Pin2, OUTPUT);
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);
  pinMode(gripperMotorPin1, OUTPUT);
  pinMode(gripperMotorPin2, OUTPUT);

  Blynk.setDeviceName("Blynk");
  Blynk.begin(auth);
}
void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
