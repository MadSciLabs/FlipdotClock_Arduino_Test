/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

int last = 0;
int num = 14;
int numDots = 7;
int index;
int dir;

int arrPins[] = { 2,3,4,5,6,7,8,9,22,23,24,25,26,27 };

void changeDot(int dotIndex, boolean on)
{
  int pin1,pin2;
  
  if (dir == 1)
  {
    pin1 = arrPins[2*dotIndex];
    pin2 = arrPins[2*dotIndex+dir];
  } else {
    pin1 = arrPins[num - 2*dotIndex];
    pin2 = arrPins[num - 2*dotIndex+dir];
  }
  
  if (on)
  {
   digitalWrite(pin1, LOW);
   digitalWrite(pin2 , HIGH);

   Serial.print("ON ");
   Serial.print(pin1);
   Serial.print(",");
   Serial.println(pin2);
  }
  else
  {
   digitalWrite(pin1, HIGH);
   digitalWrite(pin2 , LOW);

   Serial.print("OFF ");
   Serial.print(pin1);
   Serial.print(",");
   Serial.println(pin2);
  }
}

// the setup routine runs once when you press reset:
void setup() {

  // initialize the digital pin as an output.  
  Serial.begin(9600);

  index = -1;
  last = -1;
  dir = 1;

  for (int i=0; i<num; i++)
  {
    pinMode(arrPins[i], OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {

  for (index=0; index<numDots; index++)
  {
    changeDot(index,true);
  } 
  delay(200);
  
  for (index=0; index<numDots; index++)
  {
  
  changeDot(index,false);
  if (last >= 0) {
    changeDot(last,true);
  }
  last = index;
  delay(100);
  }
  
  for (index=numDots-1; index>=0; index--)
  {

  changeDot(index,false);
  changeDot(last,true);

  last = index;
  delay(100);
  }
  
  
  for (index=0; index<numDots; index++)
  {
    changeDot(index,false);
  }
  
  delay(400);
 
  for (index=0; index<numDots; index++)
  {
    changeDot(index,true);
  } 
  
  delay(400);

  for (int j=0; j<1; j++)
  {
    
  for (index=0; index<numDots; index=index+2)
  {
    changeDot(index,false);
  }
  
  delay(400);
 
  for (index=0; index<numDots; index=index+2)
  {
    changeDot(index,true);
  }
  for (index=1; index<numDots; index=index+2)
  {
    changeDot(index,false);
  } 
  
  delay(400);
  
  }

}
