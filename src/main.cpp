/**
* @file Serial_LED_Control.ino
 * @brief Controls an LED using data received from Serial1 communication.
 *
 * This program listens for characters sent through Serial1.
 * If character '1' is received, the LED on pin 13 turns ON.
 * If character '0' is received, the LED turns OFF.
 * Received characters are also printed to the Serial Monitor.
 *
 * @author Alan Crozier
 * @date 2026-02-20
 */

#include <Arduino.h>

/**
 * @brief Arduino setup function.
 *
 * Initializes LED pin as output and starts serial communication
 * for both Serial Monitor and Serial1 interface.
 * This function runs once at startup.
 */
void setup() {

    /** Configure built-in LED pin */
    pinMode(13, OUTPUT);

    /** Start serial communication */
    Serial.begin(9600);   // Serial Monitor
    Serial1.begin(9600);  // External serial device
}

/**
 * @brief Arduino main loop function.
 *
 * Checks for incoming data on Serial1.
 * - '1' turns LED ON
 * - '0' turns LED OFF
 *
 * Received characters are echoed to the Serial Monitor.
 */
void loop() {

    /** Check if data is available from Serial1 */
    if (Serial1.available()) {

        /** Read incoming character */
        char c = Serial1.read();

        /** Print received character */
        Serial.print(c);

        /** Turn LED ON if '1' is received */
        if (c == '1') {
            digitalWrite(13, HIGH);
        }

        /** Turn LED OFF if '0' is received */
        if (c == '0') {
            digitalWrite(13, LOW);
        }
    }
}