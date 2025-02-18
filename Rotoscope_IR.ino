/*
PUL+: PIN 2
PUL-, DIR-, ENA-: GND
DIR+: PIN 3
ENA+: PIN 4az

*/
#include <AccelStepper.h>
#include <Keyboard.h>

#define STEP_PIN 2    // PUL+ pin on DM542
#define DIR_PIN 3     // DIR+ pin on DM542
#define ENABLE_PIN 4  // ENA+ pin on DM542

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

const int positions[] = {0, 14630};  // 6 positions  14630 steps in total

//serial.begin(9600);

enum MotorState {
  IDLE,
  MOVING_TO_POSITION,
  RETURNING_TO_ORIGIN
};

MotorState motorState = IDLE;
int currentPositionIndex = 0;

void setup() {
  // Initialize Serial
  Serial.begin(9600);
  
  // Initialize motor control pins
  pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, LOW);
  
  stepper.setMaxSpeed(1000.0);
  stepper.setAcceleration(100.0);
  stepper.setSpeed(0);
  
  // Start the Keyboard library
  Keyboard.begin();
}

void loop() {
  // Check for incoming serial data
  if (Serial.available() > 0) {
    char receivedChar = Serial.read();  // Read the incoming byte
    
    switch (receivedChar) {
      case 'a':
        moveMotorToPosition(positions[1]);
        break;
     /* case 'b':
        moveMotorToPosition(positions[2]);
        break;
      case 'c':
        moveMotorToPosition(positions[3]);
        break;
      case 'd':
        moveMotorToPosition(positions[4]);
        break;
      case 'e':
        moveMotorToPosition(positions[5]);
        break;*/

      case 'z':  // Key for returning to origin
        returnToOrigin();
        break;
    }
  }
  
  stepper.run();

  // Check if the motor has reached its target position and simulate keypress
  if (motorState != IDLE && stepper.distanceToGo() == 0) {
    motorState = IDLE;
    simulateKeyPress(currentPositionIndex);
  }
}

void moveMotorToPosition(int position) {
  stepper.moveTo(position);
  motorState = MOVING_TO_POSITION;
  currentPositionIndex = findPositionIndex(position);
}

void returnToOrigin() {
  stepper.moveTo(positions[0]);
  motorState = RETURNING_TO_ORIGIN;
  currentPositionIndex = 0;
}

int findPositionIndex(int position) {
  for (int i = 0; i < sizeof(positions) / sizeof(positions[0]); ++i) {
    if (positions[i] == position) {
      return i;
    }
  }
  return -1;
}

void simulateKeyPress(int positionIndex) {
  switch (positionIndex) {
    case 0:
      Keyboard.press('z');
      delay(100);  // Short delay to ensure keypress is registered
      Keyboard.release('z');
      break;
    case 1:
      Keyboard.press('q');
      delay(100);
      Keyboard.release('q');
      break;
  /*  case 2:
      Keyboard.press('w');
      delay(100);
      Keyboard.release('w');
      break;
    case 3:
      Keyboard.press('e');
      delay(100);
      Keyboard.release('e');
      break;
    case 4:
      Keyboard.press('r');
      delay(100);
      Keyboard.release('r');
      break;
    case 5:
      Keyboard.press('t');
      delay(100);
      Keyboard.release('t');
      break;
  
 */
  }
}
