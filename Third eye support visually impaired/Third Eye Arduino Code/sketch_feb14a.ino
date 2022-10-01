// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 12;
const int ledPin = 11;
                            
                                  
// defines variables
long duration;
int distance;
int safetyDistance;
 
            
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
 
 
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
 
// Calculating the distance
distance= duration*0.034/2;
 
safetyDistance = distance;
if (safetyDistance <= 20)   // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
  digitalWrite(buzzer, HIGH);
  delay(900);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
  delay(900);
  digitalWrite(ledPin,LOW);
  delay(100);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}
Serial.print("Distance: ");
Serial.println(distance);
}
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 12;
const int ledPin = 11;
                            
                                  
// defines variables
long duration;
int distance;
int safetyDistance;
 
            
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop(){
if (safetyDistance <= 5)
{
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
    
  }
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
