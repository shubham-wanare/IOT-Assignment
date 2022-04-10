const int LED=15;
const int BUTTON=4;
void setup() {
  // put your setup code here, to run once:
pinMode(4,INPUT);
pinMode(15,OUTPUT);
Serial.begin(115200);
 
}

void loop() {
  // put your main code here, to run repeatedly:
/*digitalWrite(LED,HIGH);
Serial.println("LED ON\n");
delay(1000);
digitalWrite(LED,LOW);
Serial.println("LED OFF\n");
delay(1000);*/
if(digitalRead(BUTTON) == LOW) 
{

  Serial.println("LED ON\n");
  digitalWrite(LED,HIGH);
}
else
{
  Serial.println("LED OFF\n");
  digitalWrite(LED,LOW);
}
}
