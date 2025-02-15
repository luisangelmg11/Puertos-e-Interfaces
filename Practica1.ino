const int ledR=13;
const int ledA=7;
const int ledV=4;

void setup()
{
  pinMode(ledR, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledV, OUTPUT);

}

void loop()
{
  digitalWrite(ledR, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledV, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(ledR, LOW);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledV, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(ledR, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledV, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(ledR, LOW);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledV, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, LOW);
  digitalWrite(ledV, LOW);
  delay(5000); // Wait for 1000 millisecond(s)
}