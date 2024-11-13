#include <Arduino.h>

#define in1 2
#define in2 4
#define motorPin 5
#define xPin 27
#define yPin 26

// Variable for motor direction, true means forward, false means reverse
bool direction = true;

void setup() {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(motorPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Read joystick values on X and Y axes
    int x = analogRead(xPin);
    int y = analogRead(yPin);

    // Map the joystick X value to a motor speed range (0 to 255)
    int xMapped = map(abs(x - 512), 0, 1024, 0, 255); // Normalize X around center 2048
    int yMapped = map(abs(y - 512), 0, 1024, 0, 255);

        if (xMapped > -17 && xMapped < 17) {
        xMapped = 0; // Set to 0 for neutral position
    }

    // Determine motor direction based on X-axis input
    if (x >= 512) { // Positive X direction (right)
        direction = true;  // setting direction to forward
    } else { // Negative X direction (left)
        direction = false; // setting direction to reverse
    }
    //direction = x >= 2048;

    //Serial.println(x);
    Serial.println(xMapped);
    Serial.println(direction);

    // Set motor direction based on the joystick input
    digitalWrite(in1, direction);
    digitalWrite(in2, !direction);

    // Set motor speed with PWM based on mapped X value
    analogWrite(motorPin, xMapped);
    delay(100); // small delay to smooth motor response
}
