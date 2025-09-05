# Arduino-Keypad-LCD-Calculator

This project demonstrates how to build a simple **arithmetic calculator** using an **Arduino Uno R3**, **4x3 Keypad**, and a **16x2 LCD**.  
The calculator can perform basic operations: Addition, Subtraction, Multiplication, and Division.

## 📌 Features
- Takes numeric input from a 4x3 Keypad.
- Displays results on a 16x2 LCD.
- Handles division by zero errors

##  Hardware & Software Requirements
- Arduino Uno R3  
- 16x2 LCD + 10k Potentiometer (for contrast)  
- 4x3 Keypad  
- Breadboard & Jumper Wires  
- Arduino IDE (with `Keypad.h` and `LiquidCrystal.h` libraries)

  ## LCD Connections
  LCD Pin	Function	Arduino Pin
VSS	Ground (GND)	GND
VDD	+5V Power	5V
VO	Contrast (via 10k pot middle pin)	Potentiometer
RS	Register Select	D7
RW	Read/Write	GND (write only)
E	Enable	D6
D4	Data line 4	D5
D5	Data line 5	D4
D6	Data line 6	D3
D7	Data line 7	D2
A (LED+)	LCD Backlight +	5V
K (LED–)	LCD Backlight –	GND

## Keypad Connections

Keypad Pin	Function	Arduino Pin
R1	Row 1	D8
R2	Row 2	D9
R3	Row 3	D10
R4	Row 4	D11
C1	Column 1	D12
C2	Column 2	D13
C3	Column 3	A0


<img width="469" height="313" alt="image" src="https://github.com/user-attachments/assets/9eb12b8a-ed0e-49c1-9300-d446eeff0698" />

