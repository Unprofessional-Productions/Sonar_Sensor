///Name of file:  C++ Sonar Sensor Code
///@Author Benny Nicolosi

///include the Servo Motor in the code
#include <Servo.h>

///Parameter for how often to trigger Sonar Sensor
const unsigned long int interval = 10;
unsigned long int previousTime = 0;

///Global parameter for Servo Motor
Servo s1;

const int trig = 2;
const int echo = 3;
int Distance ;

///Setup
///Initialize Sensor and Motor
void setup() 
{
 
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  //Tells code what digital pin the Motor is connected to on the Arduino board
  s1.attach(4);

  //Reads Arduino data and reads it to Serial Monitor
  Serial.begin(9600);

}

///Loop
///Executes the functions of the code
void loop()
{
    
    //For loop Angle is the angle of the Motor, distance is the distance that the Sensor reads
  for(int angle=0; angle<180; angle++)
    {
        ///how often to record and print data on Serial Monitor
        unsigned long currentTime = millis();
        if(currentTime - previousTime >= interval)
        {

          s1.write(angle);
          Distance = int(readDistance());
          previousTime = currentTime;

        }

      Serial.print(angle);
      Serial.print(",");
      Serial.print(Distance);
      Serial.print(".");

    }

  ///Keeps angle from going to far
  for(int angle=180; angle>0; angle--)
    {

      ///Same as above if loop
  unsigned long currentTime = millis();
        if(currentTime - previousTime >= interval)
        {

          s1.write(angle);
          Distance = int(readDistance());
          previousTime = currentTime;

        }

      Serial.print(angle);
      Serial.print(",");
      Serial.print(Distance);
      Serial.print(".");

    }

}

float readDistance()  {

  ///trig pin transmit wave
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);

  float time = pulseIn(echo, HIGH);
  float Distance = 0.034 * time / 2;

  return Distance;

}
