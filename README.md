# JOYSTICK ZERO DELAY USING ARDUINO 

Here is the code that I wrote to use an Arduino Leonardo as a zero delay joystick's board. 
In this project I've used external 4.7k ohms resistors but you can you use the built in resistors of your board.
I've used port manipulartion to programm the port registers in this code because it's way faster than the digitalRead /Write functions. 

The three registers are DDR, PORT, and PIN.

{DDR}  Determines whether the pin is INPUT (0) or OUTPUT (1).

{PORT} Controls whether the pin is HIGH (1) or LOW (0) (Use this register if you want to use the built in resistor of your board to configure your input port as an input_pullup port.)

{PIN}  Reads the state of INPUT pins.


Library used in this project (this library only work with AtMega32u4 Arduino boards): https://github.com/MHeironimus/ArduinoJoystickLibrary
Arduino diagram: https://www.robot-italy.com/en/blog/progetti/450

