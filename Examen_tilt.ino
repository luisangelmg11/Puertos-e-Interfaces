// C++ code
//
const int tiltSensorPin=2;
const int buzzerPin=8; 

void setup()
{
  pinMode(tiltSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  int tilt=digitalRead(tiltSensorPin);
  if(tilt==HIGH){
    digitalWrite(buzzerPin, HIGH);
  }else{
    digitalWrite(buzzerPin, LOW);
  }
  
}