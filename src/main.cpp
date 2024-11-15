#include <Arduino.h>

#define in1Left 5
#define in2Left 4
#define motorPinLeft 0
#define in1Right 2
#define in2Right 3
#define motorPinRight 1
#define xPin 27
#define yPin 26

// Variable for motor direction, true means forward, false means reverse
bool directionLeft = true;
bool directionRight = true;

int turnSpeed = .5;
int speed = 2;

void setup() {
    pinMode(in1Left, OUTPUT);
    pinMode(in2Left, OUTPUT);
    pinMode(motorPinLeft, OUTPUT);
    pinMode(in1Right, OUTPUT);
    pinMode(in2Right, OUTPUT);
    pinMode(motorPinRight, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Read joystick values on X and Y axes
    int x = analogRead(xPin);
    int y = analogRead(yPin);

    // Map the joystick X value to a motor speed range (0 to 255)
    int xMapped = map(abs(x - 512), 0, 1024, 0, 255); // Normalize X around center 512
    int yMapped = map(abs(y - 512), 0, 1024, 0, 255);

        if (xMapped > -17 && xMapped < 17) {
        xMapped = 0; // Set to 0 for neutral position
    }

    // Determine motor direction based on X-axis input
    if (x >= 600) { // Positive X direction (right)
        directionLeft = true;
        directionRight = true;  // setting direction to forward
        speed = 2;
    } else if (x<400) { // Negative X direction (left)
        directionLeft = false;
        directionRight = false; // setting direction to reverse
        speed = 2;
    }
    //for right and left


    if(y>=900){
    delay(200);
        directionRight = true;
        directionLeft = false;
       // speed = turnSpeed;
    } else if(y<200) {
    delay(200);
        directionRight = false;
        directionLeft = true;
       // speed = turnSpeed; 
    }


    //direction = x >= 2048;

    //Serial.println(x);
    // Serial.println(xMapped);
    // Serial.println(yMapped);
    // Serial.println("stats");
    Serial.println("direction");
    Serial.println(directionLeft);
    Serial.println(directionRight);


    // Set motor direction based on the joystick input
    digitalWrite(in1Left, directionLeft);
    digitalWrite(in2Left, !directionLeft);

    digitalWrite(in1Right, !directionRight);
    digitalWrite(in2Right, directionRight);

    // Set motor speed with PWM based on mapped X value
    analogWrite(motorPinLeft, xMapped*speed);
    analogWrite(motorPinRight, xMapped*speed);
    delay(1); // small delay to smooth motor response
}