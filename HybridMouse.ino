#include <Mouse.h>
#include "MPU9250.h"
MPU9250 IMU(Wire, 0x68);

const int speed_mouse = 1;
#define  unfreazeCursorButton 3 // if user hold this button, gyroscope movments change the position of 3d cursor
#define  rightClickButton  4  // and 2d manipulation button
#define leftClickButton   5 
#define joystickX  A0
#define joystickY  A1

void setup() {
  IMU.begin();
  Serial.begin(9600);
  Serial.println("Hello Computer");
  pinMode(unfreazeCursorButton, INPUT_PULLUP);
  pinMode(rightClickButton, INPUT_PULLUP);
  pinMode(leftClickButton, INPUT_PULLUP);
}

void loop() {
  IMU.readSensor();

  //checking cursor button state
  
  int cursorButtonState= digitalRead(unfreazeCursorButton);
  Serial.println(" cursorButtonStatus  ");
  Serial.println(cursorButtonState);
  //checking rightClickButtonState
  int rightClickState= digitalRead(rightClickButton);
  Serial.println(" right clickstatus  ");
  Serial.println(rightClickState);
  //checking left click state
   int leftClickState= digitalRead(leftClickButton);
  Serial.println(" left clickstatus  ");
  Serial.println(leftClickState);

  //Gyroscope State
  Serial.print("x_axist:"); 
  Serial.println(IMU.getAccelX_mss());
   Serial.print("y_axis:");
  Serial.println(IMU.getAccelY_mss());
   Serial.print("Z_axis:");
  Serial.println(IMU.getAccelZ_mss());

  // Joystick Status
  int xValue = analogRead(joystickX);
  int yValue = analogRead(joystickY);
  Serial.println(" Joystick Status  X direction " );
  Serial.print(xValue);
  Serial.println(" Joystick Status  y direction " );
  Serial.print(yValue);
  delay(1000);
}
