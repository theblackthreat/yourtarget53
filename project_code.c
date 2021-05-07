const int pingPin = 7;
const int ledPin = 9;
int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
void setup() {
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  
  long duration, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if(cm < 100) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  delay(100);
  baselineTemp = 37;
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
   fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  if (celsius >= baselineTemp + 3) {
    digitalWrite(ledPin, HIGH);
   
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
long microsecondsToCentimeters(long microseconds) {
 
  return microseconds / 29 / 2;
}
