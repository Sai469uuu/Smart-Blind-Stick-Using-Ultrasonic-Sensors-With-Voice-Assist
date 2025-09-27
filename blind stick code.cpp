
#define trigPin  2
#define echoPin 3

#define ledGreen 9
#define ledRed 8

#define alarm 11

int range = 5;//range in inches

void setup() {
  
  Serial.begin(9600);
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
 
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, LOW);
  
}
void loop()
{
  
  long duration, inches, cm;

  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);

 
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  if(inches < 12) {
    Serial.println("DANGER");
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH); 
    tone(alarm, 2000); 
    delay(100);
  } else {
    Serial.println("GOOD");
     digitalWrite(ledGreen, HIGH);
     digitalWrite(ledRed, LOW); 
     noTone(alarm);
     delay(100);
  }  
  
  delay(200);
}

long microsecondsToInches(long microseconds)
{
  
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  
  return microseconds / 29 / 2;
}
