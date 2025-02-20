// C++ code
//
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int sensor= analogRead(A0);
  float voltage = sensor * (5.0/1023.0);
  float temperatura= (voltage - 0.5)*100;
  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  delay(1000);
}