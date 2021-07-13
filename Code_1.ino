int val = 0;
void setup()
{
  Serial.begin(115200);
  delay(100);
  Serial.println("AT+CWJAP=\"Simulator Wifi\",\"\"\r\n");
  delay(3000);
  pinMode(7,OUTPUT);
  pinMode (A0, INPUT);
}

void loop()
{
  val = analogRead (A0);
  Serial.println (val);
  delay(1000); // Wait for 1000 millisecond(s)
  
  Serial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
  int len = 60;
  Serial.print("AT+CIPSEND=");
  Serial.println(len);
  Serial.print ("GET /update?api_key=JEEIYRI27E8U3MZM&field1=");
  Serial.print (val);
  Serial.println (" HTTP/1.1\z\n");
 if (val<95)
  {digitalWrite (7, LOW);}
  else 
  {digitalWrite(7, HIGH);}
  Serial.println("AT+CIPCLOSE=0\r\n");
// Thingspeak free account
}




