float temp;
const int tempPin=A3; //temperature pin analog

const int trigPin  = 12;
const int echoPin  = 11;
float pingTime,distance;

//Specify digital pin on the Arduino that the positive lead of piezo buzzer is attached.
int piezoPin = 8;

int ledPin=7;

void setup() {
  // put your setup code here, to run once:
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(1500);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  pingTime=pingTime/1000000.;
  pingTime=pingTime/3600.;
  distance=776.5*pingTime;
  distance=distance/2;
  distance=distance*63360*2.54;
  Serial.println();
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println();
  Serial.println();
  delay(700);
  
  
  
  temp = analogRead(tempPin);
  temp = temp * 0.48828125;
  Serial.print("TEMPRATURE = ");
  Serial.print(temp);
  Serial.print("'C");
  Serial.println();
  delay(700);
  
  if(/*temp>45 || */distance<20)
  {
    tone(piezoPin, 1000, 500);
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin,LOW);
    delay(250);
    Serial.print("RED ALERT!!");
    Serial.println();
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
  
}
