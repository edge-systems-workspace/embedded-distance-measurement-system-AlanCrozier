#include <Arduino.h>
void setup() {
    // write your initialization code here
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    Serial1.begin(9600);
}


void loop() {
    // write your code here
    if (Serial1.available()) {
        char c = Serial1.read();
        Serial.print(c);

        if (c == '1') {
            digitalWrite(13, HIGH);
        }
        if (c == '0') {
            digitalWrite(13, LOW);
        }
    }
}