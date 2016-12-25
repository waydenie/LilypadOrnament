/*
  5 LED Random Ornament
  Blinks 5 LEDs in a random pattern.

  24 Dec 2016
*/

#define NUMLED 5
const int leds[NUMLED] = { A3, 13, 9, 5, 3 };

void setup() {
  randomSeed(analogRead(A0));
//Initialize pins as outputs and turn off to start.
  for (int i=0 ; i<NUMLED ; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i],LOW);
  }
}

void loop() {
  int randLED=0;
  
//Always toggle one of the LEDs
  randLED = random(0,NUMLED);
  digitalWrite(leds[randLED], !digitalRead(leds[randLED]));
//Sometimes, also toggle a second LED
  if (randLED%2) {
    randLED = random(0,NUMLED);
    digitalWrite(leds[randLED], !digitalRead(leds[randLED]));
  }
  
  delay(random(150,1500));
}

