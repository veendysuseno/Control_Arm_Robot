# Robot Arm Controller

This project demonstrates how to control a robotic arm with five servos using an Arduino and serial communication. The arm's servos can be controlled remotely by sending commands through the serial monitor.

## Components

- Arduino (Uno, Nano, or similar)
- 5 Servos
- Power supply for servos
- Connecting wires
- Breadboard (optional, for connections)

## Code Explanation

The code allows the control of five servos connected to the Arduino. Each servo's angle is adjusted based on commands received via the serial monitor.

### Code

```cpp
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

unsigned int sudut;
String inString="", temStr;
char str;
unsigned int nomor, l, i;

void setup(){
  Serial.begin(9600);
  servo1.attach(2);  // Pin 2 = Servo 1
  servo2.attach(3);  // Pin 3 = Servo 2
  servo3.attach(4);  // Pin 4 = Servo 3
  servo4.attach(5);  // Pin 5 = Servo 4
  servo5.attach(6);  // Pin 6 = Servo 5

  // Set initial position of servos
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);

  Serial.println("ROBOT ARM CONTROLLER");
}

void loop(){
  if (Serial.available() > 0) {
    str = Serial.read();
    if (str != '\n') {
      inString += (char)str;
    } else if (str == '\n') {
      temStr = inString.substring(0, 1);
      nomor = temStr.toInt();
      temStr = inString.substring(2);
      sudut = temStr.toInt();

      Serial.print(nomor);
      Serial.print(" : ");
      Serial.println(sudut);

      // Control the servo based on the received command
      switch (nomor) {
        case 1: servo1.write(sudut); break;
        case 2: servo2.write(sudut); break;
        case 3: servo3.write(sudut); break;
        case 4: servo4.write(sudut); break;
        case 5: servo5.write(sudut); break;
      }

      inString = "";
    }
  }
}
```

## How It Works

- Initialization: In the setup() function, the servos are attached to their respective pins, and their initial positions are set to 90 degrees.
- Serial Communication: In the loop() function, the program reads serial input. Commands are expected in the format X Y, where X is the servo number (1-5) and Y is the desired angle (0-180).
  Servo Control: Based on the received command, the corresponding servo's angle is adjusted.

## Command Format

- **The format for controlling the servos is X Y, where:** <br/>
  - X is the servo number (1 to 5). <br/>
  - Y is the angle in degrees (0 to 180). <br/>

## Example Commands

- To set Servo 1 to 45 degrees: 1 45
- To set Servo 3 to 90 degrees: 3 90

## Setup

- Connect each servo to the appropriate pin on the Arduino (2 to 6).
- Ensure the servos are powered properly. Use an external power supply if necessary.
- Upload the code to your Arduino.
- Open the Serial Monitor in the Arduino IDE, set the baud rate to 9600, and send commands in the format described above.

## Conclusion

- This project provides a basic framework for controlling a robotic arm with multiple servos using serial commands. It can be expanded with more features or integrated into more complex systems.
