const int analogPin = A0;   // the pin that the potentiometer is attached to
const int ledCount = 3;    // the number of LEDs in the bar graph
int redPin= 5;
int greenPin = 6;
int bluePin = 7;

int ledPins[] = {
  2, 3, 4
};   // an array of pin numbers to which LEDs are attached


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // loop over the pin array and set them all to output:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
  // read the potentiometer:
  int sensorReading = analogRead(analogPin);
  
  // loop over the LED array:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    
      digitalWrite(ledPins[thisLed], HIGH);
      delay(350);
      digitalWrite(ledPins[thisLed], LOW);
      delay(150);
      }
          
      setColor(255, 0, 0); // Red Color
      delay(200);
      setColor(0, 255, 0); // Green Color
      delay(200);
      setColor(0, 0, 255); // Blue Color
      delay(200);
      setColor(255, 255, 255); // White Color
      delay(200);
      setColor(170, 0, 255); // Purple Color
      delay(200);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
