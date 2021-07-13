int inches=0;
int cm=0;
int sensorReading=0;
const int trig=7;
const int echo=5;
const int rled=13;
const int bled=11;
const int gled=10;
const int buzz=12;
long readUltrasonicDistance(int trigger,int echo)
{
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  return pulseIn(echo,HIGH);
}
void setup()
{
  pinMode(A0,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(rled,OUTPUT);
  pinMode(bled,OUTPUT);
  pinMode(gled,OUTPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  sensorReading=analogRead(A0);
  Serial.println(sensorReading);
  cm=0.01723*readUltrasonicDistance(trig,echo);
  inches=(cm/2.54);
  Serial.println(inches);
  int t=sensorReading*0.76;
  if(inches<18)
  {
    light(255-t,255-t,0);
    delay(3000);
    
  }
  else
  {
    light(0,0,0);
    delay(1000);
  }
}
void light(int a,int b,int c)
{
	analogWrite(rled,a);
    analogWrite(bled,b);
    analogWrite(gled,c);
}