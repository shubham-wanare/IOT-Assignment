const int ldr=25;
const int led=21;
int val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(ldr,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

val=digitalRead(ldr);

if(val==0)
{
  digitalWrite(led,HIGH);
}
else
{
  digitalWrite(led,LOW);
}
}

