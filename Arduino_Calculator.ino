#include <Keypad.h>
#include <LiquidCrystal.h>

// LCD pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {8, 9, 10, 11};
byte colPins[COLS] = {12, 13, A0};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Variables for calculator
String num1 = "";
String num2 = "";
char op = '\0';   // operator
bool secondNumber = false;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Keypad Calculator");
  delay(1500);
  lcd.clear();
  lcd.print("Enter number...");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key >= '0' && key <= '9') { // number keys
      if (!secondNumber) {
        num1 += key;
        lcd.clear();
        lcd.print(num1);
      } else {
        num2 += key;
        lcd.clear();
        lcd.print(num1);
        lcd.setCursor(0, 1);
        lcd.print(op);
        lcd.print(num2);
      }
    }
    else if (key == '*') {  // choose operator
      if (num1 != "") {
        if (op == '\0') op = '+';  // first operator = +
        else if (op == '+') op = '-';
        else if (op == '-') op = '*';
        else if (op == '*') op = '/';
        else if (op == '/') op = '+';

        secondNumber = true;
        lcd.clear();
        lcd.print(num1);
        lcd.setCursor(0, 1);
        lcd.print(op);
      }
    }
    else if (key == '#') { // calculate (=)
      if (num1 != "" && num2 != "" && op != '\0') {
        long n1 = num1.toInt();
        long n2 = num2.toInt();
        long result = 0;

        if (op == '+') result = n1 + n2;
        else if (op == '-') result = n1 - n2;
        else if (op == '*') result = n1 * n2;
        else if (op == '/' && n2 != 0) result = n1 / n2;

        lcd.clear();
        lcd.print("Result:");
        lcd.setCursor(0, 1);
        lcd.print(result);

        // reset for next calc
        num1 = "";
        num2 = "";
        op = '\0';
        secondNumber = false;
        delay(3000);
        lcd.clear();
        lcd.print("Enter number...");
      }
    }
  }
}
