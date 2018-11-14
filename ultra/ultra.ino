const int trigPin  = A1;
const int echoPin  = A2;
float duration, distance;     
char msg[6];


void setup()
{
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    Serial.begin(9600); 
}

void loop()
{
     digitalWrite(trigPin, LOW); 
     delay(500); 
    digitalWrite(trigPin, HIGH); 
     delay(500); 
    digitalWrite(trigPin, LOW); 
    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2; 
    Serial.print("Distance: "); 
    Serial.println(distance);     
    dtostrf(distance, 6,2,msg);           //converts the float into a char 
    vw_send((uint8_t *)msg, strlen(msg)); //transmits the data
    vw_wait_tx(); // Wait until the whole message is gone
    delay(500);
 }
 
