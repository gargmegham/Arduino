#include <VirtualWire.h> //Load the library

const int trigPin  = A0;
const int echoPin  = A1;
float duration, distance;     
char msg[6];


void setup()
{
    vw_set_tx_pin(12);          // Sets pin D12 as the TX pin
    vw_setup(2000);          // Bits per sec
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
 
