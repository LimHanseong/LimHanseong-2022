#include<Servo.h>
#include <LiquidCrystal.h>
//Declaration of macro constants
#define Open 90
#define Close 0
#define Maxppm 3500
#define Minppm 400
// Declare pin numbers and declare global variables
int GasPin = A0;
int SwitchPin = 12;
int RedLEDPin = 11;
int YellowLEDPin = 10;
int BlueLEDPin = 9;
int ServoPin = 8;
int ndelay = 50;
Servo mServoMotor;
LiquidCrystal mLcd(2, 3, 4, 5, 6, 7);
//Declaration of Structure for Contaminants
struct PollutantsList
{
  int Warning_ppm;
  int Action_ppm;
};
// Functions to run when action is required
void Action(void)
{
  digitalWrite(RedLEDPin, HIGH);
  digitalWrite(YellowLEDPin, LOW);
  digitalWrite(BlueLEDPin, LOW);
  mLcd.setCursor(0,2);                //Specifying the output position
  mLcd.print("Take action.");         //lcd output
  delay(ndelay);
}
//Function to alert
void Warning(void)
{
  digitalWrite(RedLEDPin, LOW);
  digitalWrite(YellowLEDPin, HIGH);
  digitalWrite(BlueLEDPin, LOW);
  mLcd.setCursor(0,2);
  mLcd.print("Caution required.");
  delay(ndelay);
}
//Steady state notification function
void Normal(void)
{
  digitalWrite(RedLEDPin, LOW);
    digitalWrite(YellowLEDPin, LOW);
    digitalWrite(BlueLEDPin, HIGH);
    mLcd.setCursor(0,2);
    mLcd.print("Normal.");
    delay(ndelay);
}
// Setting the device
void setup()
{
  pinMode(SwitchPin,INPUT);
  pinMode(RedLEDPin,OUTPUT);
  pinMode(YellowLEDPin,OUTPUT);
  pinMode(BlueLEDPin,OUTPUT);
  mServoMotor.attach(ServoPin);
  mLcd.begin(16, 2);            //Specifying lcd Size
  Serial.begin(9600);
}

void loop()
{
  //Declare and initialize variables
  struct PollutantsList CO2;
  int value = analogRead(A0);
  CO2.Warning_ppm = 1000;
  CO2.Action_ppm=2000;
  
  int Power = digitalRead(SwitchPin); //Check switch status
  
  int ppm = map(value, 20,120,Minppm,Maxppm); //Mapping
  //Output ppm to lcd
  mLcd.clear();
  mLcd.print("ppm: ");
  mLcd.print(ppm);
  //If the switch is on,
  if(Power == HIGH)
  {
    mLcd.print("   ON");
    if(ppm<CO2.Warning_ppm)
    {
      Normal();
      mServoMotor.write(Close);
    }
    else if (ppm<CO2.Action_ppm)
    {
      Warning();
    }
    else
    {
      Action();
      mServoMotor.write(Open);
    }
  }
  //If the switch is off,
  else
  {
    mLcd.print("   OFF");
    if(ppm<CO2.Warning_ppm)
    {
      Normal();
    }
    else if (ppm<CO2.Action_ppm)
    {
      Warning();
    }
    else
    {
      Action();
    }
  }
  delay(ndelay);
}
