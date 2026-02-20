#include <Arduino.h>

/**
 * @file `main.cpp`
 * @brief Embedded distance measurement using HC-SR04 ultrasonic sensor.
 * @details Measures distance with an HC-SR04 ultrasonic sensor and prints
 *          structured output to the Serial Monitor.
 * @author  yatendraguptacsaiml24-hub (Yatendra Kumar Gupta)
 * @date   20-02-2026
 */

int TRIG_pin = 9;
int ECHO_pin = 10;

long duration;
float distance;

/**
 * @brief Arduino setup function.
 * @details Initializes Serial communication at 9600 baud and configures
 *          the TRIG and ECHO pins for the ultrasonic sensor.
 * @return void
 */
void setup() {
    Serial.begin(9600);

    pinMode(TRIG_pin, OUTPUT);
    pinMode(ECHO_pin, INPUT);

    Serial.println("Ultrasonic Sensor System Initialized");
}

/**
 * @brief Arduino main loop function.
 * @details Sends a trigger pulse to the HC-SR04, measures the echo pulse
 *          duration, converts the duration to distance in centimeters,
 *          and prints the result to the Serial Monitor.
 * @return void
 */
void loop() {
    digitalWrite(TRIG_pin, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_pin, LOW);

    duration = pulseIn(ECHO_pin, HIGH);

    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}
