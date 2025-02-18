# Stepper Motor Control with Keyboard Simulation

This project controls a stepper motor using a **DM542 stepper driver** and simulates keyboard input based on the motor's position. The motor moves to predefined positions upon receiving commands over **Serial communication** and sends simulated keypresses via the **Keyboard** library when the motor reaches a target position.

## Features
- **Stepper motor control**: Moves to predefined positions using an **AccelStepper** library.
- **Keyboard simulation**: Sends keyboard keypresses to the connected computer based on the motor’s position (via the **Keyboard** library).
- **Serial input**: Accepts commands through Serial to move the motor to specific positions or return to the origin.

## Hardware Requirements
- Stepper motor (e.g., NEMA 17 or compatible)
- Stepper motor driver (e.g., DM542)
- Arduino or compatible microcontroller (with USB support for serial/keyboard functions)
- Jumper wires for connections

## Pin Configuration
- **STEP_PIN (PUL+)**: Pin 2 (connected to PUL+ on DM542)
- **DIR_PIN (DIR+)**: Pin 3 (connected to DIR+ on DM542)
- **ENABLE_PIN (ENA+)**: Pin 4 (connected to ENA+ on DM542)
- **GND**: Connected to DIR-, PUL-, ENA- pins on DM542

## How to Use
1. **Upload the code** to your Arduino board.
2. **Wire the stepper motor** and DM542 stepper driver to the appropriate pins.
3. **Open the Serial Monitor** (set baud rate to 9600).
4. Send the following commands via Serial:
   - `'a'`: Move to the first position (14630 steps).
   - `'z'`: Return to the origin (Position 0).

5. The **Keyboard** library will simulate keypresses when the motor reaches its target position:
   - Position 0: Sends keypress `'z'`.
   - Position 1: Sends keypress `'q'`.

## Code Overview
- **AccelStepper**: Used to control the stepper motor with smooth acceleration and deceleration.
- **Keyboard**: Simulates keypresses on a connected computer based on the motor’s position.
- **Serial Input**: Commands are received via the Serial Monitor to move the motor or return it to the origin.

### Example Interaction:
- **Command**: Send `'a'` to move the motor to Position 1.
- **Motor reaches Position 1**: Simulates the keypress `'q'`.

## License
This project is open-source and available under the MIT License.

## Acknowledgements
- The project uses the **AccelStepper** library for motor control.
- The **Keyboard** library is used to simulate keypresses on the computer.
- For more information on the **AccelStepper** library, visit the [AccelStepper Documentation](http://www.airspayce.com/mikem/arduino/AccelStepper/).

---

Enjoy controlling your stepper motor and simulating keyboard input with this project!
