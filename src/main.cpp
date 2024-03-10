#include <Arduino.h>
#include <Servo.h>

// esc pin (it can be any PWM pin)
#define ESC_PIN 9

// Create a new instance of the Server class
Servo esc;

// Function to calibrate the ESC
void calibrateESC();

void setup()
{
  calibrateESC();
  esc.write(5);
}

void loop()
{
}

void calibrateESC()
{
  /*
    attach(pin, min, max)-> default min value is 544 and max value is 2400 in servo library
    but for ESC the min value can be 1000 and max value can be 2000
    these values are in the micro-seconds
  */
  esc.attach(ESC_PIN, 1000, 2000);
  esc.write(180);
  delay(5000);
  esc.write(0);
  delay(2000);
}
