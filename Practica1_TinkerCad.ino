// Practica1 - Programación de Puertos e Interfaces
// Autor - Montoya Garza Luis Angel
//

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
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledV, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(ledR, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledV, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
