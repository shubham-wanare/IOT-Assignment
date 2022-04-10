const int button=0;
const int buzzer=2;
int val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(button,INPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val=digitalRead(button);
Serial.println(val);
if(val==0)
{
  delay(5000);
  digitalWrite(buzzer,1);
}
else
{
  digitalWrite(buzzer,0);
}
}
