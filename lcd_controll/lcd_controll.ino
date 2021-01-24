#include "buttonManager.h"
#include "taskCountMode.h"
#include "lcdManager.h"

// initialize the library with the numbers of the interface pins
#include <LiquidCrystal.h>

// assigning the pin numbers
#define LEFT_Button_PIN 7
#define RIGHT_Button_PIN 8

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

LcdManager* lcdM = new LcdManager();

// Creating all mode objects:
TaskCountMode taskCountMode = TaskCountMode(lcdM);
Mode * currentMode = &taskCountMode;

void rightButtonPressed() {
  currentMode->rightButtonPressed();
}

void leftButtonPressed() {
  currentMode->leftButtonPressed();
}

// Define which funktion is called when Buton is pressed
ButtonManager leftBtnManager(LEFT_Button_PIN, &leftButtonPressed);
ButtonManager rightBtnManager(RIGHT_Button_PIN, &rightButtonPressed);

void setup() {
  pinMode(LEFT_Button_PIN, INPUT);
  pinMode(RIGHT_Button_PIN, INPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  Serial.begin(9600);

  currentMode->initialize();
}

void loop() {
  rightBtnManager.handleButton();
  leftBtnManager.handleButton();

  if (lcdM->hasDisplayedTextChanged()) {
    lcd.clear();
    lcd.home();
    lcd.print(lcdM->getDisplayedText());
    Serial.println(lcdM->getDisplayedText());
  }
  
  lcd.display();
}
