/*
   Created by ArduinoGetStarted.com

   This example code is in the public domain

   Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-servo-motor
*/

#include <Servo.h>
#include <ezButton.h>

// constants won't change
const int IN_BUTTON_PIN = 6; // Arduino pin connected to button's pin
const int OUT_BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int BROW_DOWN_BUTTON_PIN = 10; // Arduino pin connected to button's pin
const int BROW_UP_BUTTON_PIN = 11; // Arduino pin connected to button's pin

const int LEFT_SERVO_PIN  = 3; // Arduino pin connected to servo motor's pin
const int RIGHT_SERVO_PIN  = 4; // Arduino pin connected to servo motor's pin
const int EYE_SERVO_PIN  = 9; // Arduino pin connected to servo motor's pin


ezButton Inbutton(IN_BUTTON_PIN); // create ezButton object that attach to pin 7;
ezButton Outbutton(OUT_BUTTON_PIN); // create ezButton object that attach to pin 7;
ezButton Downbutton(BROW_DOWN_BUTTON_PIN); // create ezButton object that attach to pin 7;
ezButton Upbutton(BROW_UP_BUTTON_PIN); // create ezButton object that attach to pin 7;

Servo Left_servo;                 // create servo object to control a servo
Servo Right_servo;                 // create servo object to control a servo
Servo Eye_servo;

// variables will change:
int earangle = 90; // the current angle of servo motor
int eyeangle = 50;

void setup() {
  Serial.begin(9600);         // initialize serial
  Inbutton.setDebounceTime(50); // set debounce time to 50 milliseconds
  Outbutton.setDebounceTime(50); // set debounce time to 50 milliseconds
  Upbutton.setDebounceTime(50); // set debounce time to 50 milliseconds
  Downbutton.setDebounceTime(50); // set debounce time to 50 milliseconds

  Left_servo.attach(LEFT_SERVO_PIN);    // attaches the servo on pin 9 to the servo object
  Left_servo.write(earangle);
  Right_servo.attach(RIGHT_SERVO_PIN);    // attaches the servo on pin 9 to the servo object
  Right_servo.write(earangle);
  Eye_servo.attach(EYE_SERVO_PIN);
  Eye_servo.write(eyeangle);
}

void loop() {
  Inbutton.loop(); // MUST call the loop() function first
  Outbutton.loop(); // MUST call the loop() function first
  Upbutton.loop();
  Downbutton.loop();

  if (Inbutton.isPressed()) {
    Serial.println("The Inbutton is pressed");
    Left_servo.write(earangle + 40);
    Right_servo.write(earangle - 40);
  }
  if (Inbutton.isReleased()) {
    Serial.println("The Inbutton is released");
    Left_servo.write(earangle);
    Right_servo.write(earangle);
  }
  if (Outbutton.isPressed()) {
    Serial.println("The Outbutton is pressed");
    Left_servo.write(earangle - 40);
    Right_servo.write(earangle + 40);
  }
  if (Outbutton.isReleased()) {
    Serial.println("The Outbutton is released");
    Left_servo.write(earangle);
    Right_servo.write(earangle);
  }
  if (Upbutton.isPressed()) {
    Serial.println("The Upbutton is pressed");
    Eye_servo.write(eyeangle - 25);
  }
  if (Upbutton.isReleased()) {
    Serial.println("The Upbutton is released");
    Eye_servo.write(eyeangle);
  }
  if (Downbutton.isPressed()) {
    Serial.println("The Downbutton is pressed");
    Eye_servo.write(eyeangle + 100);
  }
  if (Downbutton.isReleased()) {
    Serial.println("The Outbutton is released");
    Eye_servo.write(eyeangle);
  }
  delay(10);
}
