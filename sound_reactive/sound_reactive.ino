//Parameters
const int micPin  = A0;
const int r = 7;
const int g = 6;
const int b = 5;

//Variables
int micVal  = 0;

void setup() {
 //Init Serial USB
 Serial.begin(9600);
 Serial.println(F("Initialize System"));
 //Init Microphone
 pinMode(micPin, INPUT);
 pinMode(r,OUTPUT);
 pinMode(g,OUTPUT);
 pinMode(b,OUTPUT);
}
void loop() {
 readMicrophone();
}

void readMicrophone( ) { /* function readMicrophone */
 ////Test routine for Microphone
 micVal = analogRead(micPin);
 Serial.println(micVal);
 if(micVal > 300)
 {
   if(micVal%3 == 0)
   {
      analogWrite(r,micVal);
   }
   else if(micVal%2 == 0)
   {
      analogWrite(g,micVal);
   }
   else
   {
      analogWrite(b,micVal);
   }
 }
 else
 {
  offAll();
 }
}

void offAll()
{
 digitalWrite(r,LOW);
 digitalWrite(g,LOW);
 digitalWrite(b,LOW);
}
