#include <Servo.h>

#define MinAngle 0
#define MaxAngle 180
#define MinPoten 0
#define MaxPoten 1023
#define mSize 5
#define Left 80
#define Right 100
#define NumMinAngle 4
#define NumMaxAngle 3
#define NumMinPoten 1
#define NumMaxPoten 2

int nGreenPin = 3;
int nBluePin = 4;
int nYellowPin = 5;
int nServoPin = 6;
int nPotenPin = A0;
int nDelay = 20;

Servo mServoMotor;

void setup()
{
  pinMode(nGreenPin, OUTPUT);
  pinMode(nBluePin, OUTPUT);
  pinMode(nYellowPin, OUTPUT);
  Serial.begin(9600);
  mServoMotor.attach(nServoPin);
}

int Maping(int Value, int *pValue)
{
  int nPWM;
  nPWM = map(Value, pValue[NumMinPoten], pValue[NumMaxPoten], pValue[NumMaxAngle], pValue[NumMinAngle]);
  
  return nPWM;
}

void loop()
{
  int readValue = analogRead(nPotenPin);
  int Reference_value[mSize] = {MinPoten, MaxPoten, MinAngle, MaxAngle};
  int *pValue = Reference_value;
  int nPWM = Maping(readValue, pValue);
  
  Serial.print("Analog: ");
  Serial.println(readValue);
  Serial.print("PWM: ");
  Serial.println(nPWM);
  
  mServoMotor.write(nPWM);
  delay(15);
  
  if (nPWM < Left)
  {
    digitalWrite(nYellowPin, LOW);
    Serial.print("nYellowPin: OFF\n");
    delay(nDelay); // Wait for 100 millisecond(s)
    digitalWrite(nBluePin, LOW);
    Serial.print("BlueLED: OFF\n");
    delay(nDelay); // Wait for 100 millisecond(s)
    digitalWrite(nGreenPin, HIGH);
    Serial.print("BlueLED: ON\n");
    delay(nDelay); // Wait for 100 millisecond(s)
  }
  else if(nPWM > Right)
  {
    digitalWrite(nYellowPin, HIGH);
    Serial.print("nYellowPin: ON\n");
    delay(nDelay); // Wait for 100 millisecond(s)
    digitalWrite(nBluePin, LOW);
    Serial.print("BlueLED: OFF\n");
    delay(nDelay); // Wait for 100 millisecond(s)
    digitalWrite(nGreenPin, LOW);
    Serial.print("BlueLED: OFF\n");
    delay(nDelay); // Wait for 100 millisecond(s)
  }
  else
  {
    digitalWrite(nYellowPin, LOW);
    Serial.print("nYellowPin: OFF\n");
    delay(nDelay); // Wait for 100 millisecond(s)
    digitalWrite(nBluePin, HIGH);
    Serial.print("BlueLED: ON\n");
    delay(nDelay); // Wait for 100 millisecond(s)
    digitalWrite(nGreenPin, LOW);
    Serial.print("BlueLED: OFF\n");
    delay(nDelay); // Wait for 100 millisecond(s)
  }
}
