#include <Arduino.h>

#define in1Left 2
#define in2Left 4
#define motorPinLeft 5
#define in1Right
#define in2Right
#define motorPinRight 
#define xPin 27
#define yPin 26

// Variable for motor direction, true means forward, false means reverse
bool directionLeft = true;
bool directionRight = true;

void setup() {
    pinMode(in1Left, OUTPUT);
    pinMode(in2Left, OUTPUT);
    pinMode(motorPinLeft, OUTPUT);
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
        directionLeft = true;  // setting direction to forward
    } else { // Negative X direction (left)
        directionLeft = false; // setting direction to reverse
    }
    //direction = x >= 2048;

    //Serial.println(x);
    Serial.println(xMapped);
    Serial.println(directionLeft);

    // Set motor direction based on the joystick input
    digitalWrite(in1Left, direction1);
    digitalWrite(in2Left, !direction1);

    // Set motor speed with PWM based on mapped X value
    analogWrite(motorPinLeft, xMapped);
    delay(100); // small delay to smooth motor response
}
