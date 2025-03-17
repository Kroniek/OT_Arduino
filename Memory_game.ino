#include "arduino_secrets.h"

/*#include <Tone.h>

Tone speakerpin;

// LED and button pin definitions
int ledpin[] = {8, 9, 10, 11};
int buttonpin[] = {2, 3, 4, 5};
int buttonState[4] = {0, 0, 0, 0};

// Game variables
int sequence[100];
int level = 0;
int currentStep = 0;
bool playerTurn = false;

void setup() {
  Serial.begin(9600);
  speakerpin.begin(6); // Speaker connected to pin 6

  // Set LED pins as OUTPUT and turn them off
  for (int i = 0; i < 4; i++) {
    pinMode(ledpin[i], OUTPUT);
    digitalWrite(ledpin[i], LOW);

    // Set button pins as INPUT_PULLUP
    pinMode(buttonpin[i], INPUT_PULLUP);
  }

  startGame();
}

void loop() {
  if (!playerTurn) {
    playSequence();
    playerTurn = true;
  } else {
    checkPlayerInput();
  }
}

void startGame() {
  Serial.println("Game Starting!");
  randomSeed(analogRead(A0)); // Use analog pin noise for random seed
  level = 1;
  generateSequence();
}

void generateSequence() {
  for (int i = 0; i < 100; i++) {
    sequence[i] = random(1, 5); // Random number between 1 and 4
  }
}

void playSequence() {
  Serial.print("Playing level: ");
  Serial.println(level);

  for (int i = 0; i < level; i++) {
    playNoteForValue(sequence[i]);
    delay(500); // Delay between notes
  }

  currentStep = 0; // Reset player progress for the level
}

void playNoteForValue(int value) {
  Serial.print("Playing value: ");
  Serial.println(value);

  turnOffAllLEDs(); // Ensure all LEDs are off before turning on the next one

  switch (value) {
    case 1:
      digitalWrite(ledpin[0], HIGH);
      speakerpin.play(NOTE_G3, 300);
      break;
    case 2:
      digitalWrite(ledpin[1], HIGH);
      speakerpin.play(NOTE_A3, 300);
      break;
    case 3:
      digitalWrite(ledpin[2], HIGH);
      speakerpin.play(NOTE_B3, 300);
      break;
    case 4:
      digitalWrite(ledpin[3], HIGH);
      speakerpin.play(NOTE_C4, 300);
      break;
  }

  delay(400);
  turnOffAllLEDs();
  speakerpin.stop();
}

void checkPlayerInput() {
  for (int i = 0; i < 4; i++) {
    buttonState[i] = digitalRead(buttonpin[i]);
    if (buttonState[i] == LOW) { // Button is pressed
      delay(200); // Debounce delay

      // Check if the input matches the sequence
      if (sequence[currentStep] == i + 1) {
        playNoteForValue(i + 1); // Provide feedback
        currentStep++;

        // If player completes the level
        if (currentStep == level) {
          level++;
          playerTurn = false;
          delay(1000); // Short delay before next level
        }
      } else {
        // Player made a mistake
        gameOver();
        return;
      }
    }
  }
}

void gameOver() {
  Serial.println("Game Over!");
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledpin[i], HIGH); // Turn all LEDs on
  }
  delay(2000);
  turnOffAllLEDs();
  startGame(); // Restart the game
}

void turnOffAllLEDs() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledpin[i], LOW);
  }
}
*/
/* //Without sound only led
#include <Tone.h>

Tone speakerpin;

// LED and button pin definitions
int ledpin[] = {8, 9, 10, 11};
int buttonpin[] = {2, 3, 4, 5};
int resetButton = 7; // New reset button on pin 7
int buttonState[4] = {0, 0, 0, 0};

// Game variables
int sequence[100];
int level = 0;
int currentStep = 0;
bool playerTurn = false;

void setup() {
  Serial.begin(9600);
  speakerpin.begin(6); // Speaker connected to pin 6

  // Set LED pins as OUTPUT and turn them off
  for (int i = 0; i < 4; i++) {
    pinMode(ledpin[i], OUTPUT);
    digitalWrite(ledpin[i], LOW);

    // Set button pins as INPUT_PULLUP
    pinMode(buttonpin[i], INPUT_PULLUP);
  }

  // Set reset button as INPUT_PULLUP
  pinMode(resetButton, INPUT_PULLUP);

  startGame();
}

void loop() {
  // Check for reset button press
  if (digitalRead(resetButton) == LOW) {
    delay(200); // Debounce delay
    startGame();
    return;
  }

  if (!playerTurn) {
    playSequence();
    playerTurn = true;
  } else {
    checkPlayerInput();
  }
}

void startGame() {
  Serial.println("Game Starting!");
  randomSeed(analogRead(A0)); // Use analog pin noise for random seed
  level = 1;
  currentStep = 0;
  generateSequence();
  playerTurn = false;
}

void generateSequence() {
  for (int i = 0; i < 100; i++) {
    sequence[i] = random(1, 5); // Random number between 1 and 4
  }
}

void playSequence() {
  Serial.print("Playing level: ");
  Serial.println(level);

  for (int i = 0; i < level; i++) {
    playNoteForValue(sequence[i]);
    delay(500); // Delay between notes
  }

  currentStep = 0; // Reset player progress for the level
}

void playNoteForValue(int value) {
  Serial.print("Playing value: ");
  Serial.println(value);

  turnOffAllLEDs(); // Ensure all LEDs are off before turning on the next one

  switch (value) {
    case 1:
      digitalWrite(ledpin[0], HIGH);
      speakerpin.play(NOTE_G3, 300);
      break;
    case 2:
      digitalWrite(ledpin[1], HIGH);
      speakerpin.play(NOTE_A3, 300);
      break;
    case 3:
      digitalWrite(ledpin[2], HIGH);
      speakerpin.play(NOTE_B3, 300);
      break;
    case 4:
      digitalWrite(ledpin[3], HIGH);
      speakerpin.play(NOTE_C4, 300);
      break;
  }

  delay(400);
  turnOffAllLEDs();
  speakerpin.stop();
}

void checkPlayerInput() {
  for (int i = 0; i < 4; i++) {
    buttonState[i] = digitalRead(buttonpin[i]);
    if (buttonState[i] == LOW) { // Button is pressed
      delay(200); // Debounce delay

      // Check if the input matches the sequence
      if (sequence[currentStep] == i + 1) {
        playNoteForValue(i + 1); // Provide feedback
        currentStep++;

        // If player completes the level
        if (currentStep == level) {
          level++;
          playerTurn = false;
          delay(1000); // Short delay before next level
        }
      } else {
        // Player made a mistake
        gameOver();
        return;
      }
    }
  }
}

void gameOver() {
  Serial.println("Game Over!");
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledpin[i], HIGH); // Turn all LEDs on
  }
  delay(2000);
  turnOffAllLEDs();
  Serial.println("Press the reset button to restart.");
}

void turnOffAllLEDs() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledpin[i], LOW);
  }
}
*/
/*// With sound and led
#include <Arduino.h>

// Define buzzer and reset button pins
const int buzzerPin = 12;     // Buzzer connected to pin 12
const int resetButtonPin = 6; // Reset button connected to pin 6

// Button and LED pin definitions
const int buttonPins[] = {2, 3, 4, 5};   // Button input pins
const int ledPins[] = {8, 9, 10, 11};    // LED output pins

// Game variables
int sequence[100];
int inputSequence[100];
int sequenceLength = 0;
int inputIndex = 0;

// Game states
bool gameOver = false;

// Tones for win and game over
void playWinTone() {
  tone(buzzerPin, 1000, 200);  // Play a tone of 1000 Hz for 200 ms
  delay(300);
  tone(buzzerPin, 1200, 200);
  delay(300);
  noTone(buzzerPin);
}

void playGameOverTone() {
  tone(buzzerPin, 200, 300);   // Play a low tone for 300 ms
  delay(400);
  tone(buzzerPin, 100, 300);
  delay(400);
  noTone(buzzerPin);
}

// Setup function
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(resetButtonPin, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Start the game
  startGame();
}

// Function to start the game
void startGame() {
  sequenceLength = 0;
  inputIndex = 0;
  gameOver = false;
  Serial.println("Game Started");
  addToSequence();
  playSequence();
}

// Function to add a random LED to the sequence
void addToSequence() {
  sequence[sequenceLength] = random(0, 4);  // Generate a random number between 0 and 3
  sequenceLength++;
}

// Function to play the current sequence
void playSequence() {
  for (int i = 0; i < sequenceLength; i++) {
    int led = sequence[i];
    digitalWrite(ledPins[led], HIGH);
    tone(buzzerPin, 800, 200);  // Play tone while LED is on
    delay(400);
    digitalWrite(ledPins[led], LOW);
    noTone(buzzerPin);
    delay(200);
  }
  inputIndex = 0;  // Reset input index for the player's turn
}

// Function to handle game over
void handleGameOver() {
  gameOver = true;

  // Turn on all LEDs
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
  }

  // Play game-over tone
  playGameOverTone();

  // Wait for reset button press
  while (digitalRead(resetButtonPin) == HIGH) {
    // Do nothing until reset button is pressed
  }

  // Turn off all LEDs and restart the game
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  startGame();
}

// Loop function
void loop() {
  if (gameOver) {
    handleGameOver();
    return;
  }

  if (digitalRead(resetButtonPin) == LOW) {
    startGame();
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      digitalWrite(ledPins[i], HIGH);
      tone(buzzerPin, 1000, 200);  // Play tone when button is pressed
      delay(300);
      digitalWrite(ledPins[i], LOW);
      noTone(buzzerPin);

      if (i == sequence[inputIndex]) {
        inputIndex++;
        if (inputIndex == sequenceLength) {
          playWinTone();
          delay(1000);
          addToSequence();
          playSequence();
        }
      } else {
        handleGameOver();
      }
      delay(300);  // Debounce delay
    }
  }
}
*/
/*
// With sound and led and Lcd
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address (0x27 is common, but it may vary depending on your module)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define buzzer and reset button pins
const int buzzerPin = 12;     // Buzzer connected to pin 12
const int resetButtonPin = 6; // Reset button connected to pin 6

// Button and LED pin definitions
const int buttonPins[] = {2, 3, 4, 5};   // Button input pins
const int ledPins[] = {8, 9, 10, 11};    // LED output pins

// Game variables
int sequence[100];
int inputSequence[100];
int sequenceLength = 0;
int inputIndex = 0;

// Game states
bool gameOver = false;

// Tones for win and game over
void playWinTone() {
  tone(buzzerPin, 1000, 200);  // Play a tone of 1000 Hz for 200 ms
  delay(300);
  tone(buzzerPin, 1200, 200);
  delay(300);
  noTone(buzzerPin);
}

void playGameOverTone() {
  tone(buzzerPin, 200, 300);   // Play a low tone for 300 ms
  delay(400);
  tone(buzzerPin, 100, 300);
  delay(400);
  noTone(buzzerPin);
}

// Setup function
void setup() {
  Serial.begin(9600);
  lcd.init();             // Initialize the LCD
  lcd.backlight();        // Turn on the LCD backlight
  lcd.setCursor(0, 0);
  lcd.print("Aero Memory"); // Display the heading

  pinMode(buzzerPin, OUTPUT);
  pinMode(resetButtonPin, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  delay(2000); // Wait for 2 seconds before starting the game
  startGame();
}

// Function to start the game
void startGame() {
  sequenceLength = 0;
  inputIndex = 0;
  gameOver = false;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Start");

  Serial.println("Game Started");
  addToSequence();
  playSequence();
}

// Function to add a random LED to the sequence
void addToSequence() {
  sequence[sequenceLength] = random(0, 4);  // Generate a random number between 0 and 3
  sequenceLength++;
}

// Function to play the current sequence
void playSequence() {
  for (int i = 0; i < sequenceLength; i++) {
    int led = sequence[i];
    digitalWrite(ledPins[led], HIGH);
    tone(buzzerPin, 600, 350);  // Play tone while LED is on
    delay(400);
    digitalWrite(ledPins[led], LOW);
    noTone(buzzerPin);
    delay(200);
  }
  inputIndex = 0;  // Reset input index for the player's turn
}

// Function to handle game over
void handleGameOver() {
  gameOver = true;

  // Turn on all LEDs
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
  }

  // Display Game Over on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Over!");

  // Play game-over tone
  playGameOverTone();

  // Wait for reset button press
  while (digitalRead(resetButtonPin) == HIGH) {
    // Do nothing until reset button is pressed
  }

  // Turn off all LEDs and restart the game
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  startGame();
}

// Loop function
void loop() {
  if (gameOver) {
    handleGameOver();
    return;
  }

  if (digitalRead(resetButtonPin) == LOW) {
    startGame();
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      digitalWrite(ledPins[i], HIGH);
      tone(buzzerPin, 1000, 100);  // Play tone when button is pressed
      delay(300);
      digitalWrite(ledPins[i], LOW);
      noTone(buzzerPin);

      if (i == sequence[inputIndex]) {
        inputIndex++;
        if (inputIndex == sequenceLength) {
          playWinTone();
          delay(1000);
          addToSequence();
          playSequence();
        }
      } else {
        handleGameOver();
      }
      delay(300);  // Debounce delay
    }
  }
}
*/ 
/*
// with level 
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address (0x27 is common, but it may vary depending on your module)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define buzzer and reset button pins
const int buzzerPin = 12;     // Buzzer connected to pin 12
const int resetButtonPin = 6; // Reset button connected to pin 6

// Button and LED pin definitions
const int buttonPins[] = {2, 3, 4, 5};   // Button input pins
const int ledPins[] = {8, 9, 10, 11};    // LED output pins

// Game variables
int sequence[100];
int inputSequence[100];
int sequenceLength = 0;
int inputIndex = 0;
int level = 1;  // Track the game level

// Game states
bool gameOver = false;

// Tones for win and game over
void playWinTone() {
  tone(buzzerPin, 1000, 200);  // Play a tone of 1000 Hz for 200 ms
  delay(300);
  tone(buzzerPin, 1200, 200);
  delay(300);
  noTone(buzzerPin);
}

void playGameOverTone() {
  tone(buzzerPin, 200, 300);   // Play a low tone for 300 ms
  delay(400);
  tone(buzzerPin, 100, 300);
  delay(400);
  noTone(buzzerPin);
}

// Setup function
void setup() {
  Serial.begin(9600);
  lcd.init();             // Initialize the LCD
  lcd.backlight();        // Turn on the LCD backlight
  lcd.setCursor(0, 0);
  lcd.print("Aero Memory"); // Display the heading

  pinMode(buzzerPin, OUTPUT);
  pinMode(resetButtonPin, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  delay(2000); // Wait for 2 seconds before starting the game
  startGame();
}

// Function to start the game
void startGame() {
  sequenceLength = 0;
  inputIndex = 0;
  level = 1;        // Reset the level to 1
  gameOver = false;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Start");

  displayLevel();   // Display the current level

  Serial.println("Game Started");
  addToSequence();
  playSequence();
}

// Function to add a random LED to the sequence
void addToSequence() {
  sequence[sequenceLength] = random(0, 4);  // Generate a random number between 0 and 3
  sequenceLength++;
}

// Function to play the current sequence
void playSequence() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Watch Sequence");

  for (int i = 0; i < sequenceLength; i++) {
    int led = sequence[i];
    digitalWrite(ledPins[led], HIGH);
    tone(buzzerPin, 600, 350);  // Play tone while LED is on
    delay(400);
    digitalWrite(ledPins[led], LOW);
    noTone(buzzerPin);
    delay(200);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Your Turn");
  inputIndex = 0;  // Reset input index for the player's turn
}

// Function to handle game over
void handleGameOver() {
  gameOver = true;

  // Turn on all LEDs
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
  }

  // Display Game Over on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Over!");

  // Play game-over tone
  playGameOverTone();

  // Wait for reset button press
  while (digitalRead(resetButtonPin) == HIGH) {
    // Do nothing until reset button is pressed
  }

  // Turn off all LEDs and restart the game
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  startGame();
}

// Function to display the current level
void displayLevel() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Level: ");
  lcd.print(level);
  Serial.print("Level: ");
  Serial.println(level);
  delay(2000);  // Display the level for 2 seconds
}

// Loop function
void loop() {
  if (gameOver) {
    handleGameOver();
    return;
  }

  if (digitalRead(resetButtonPin) == LOW) {
    startGame();
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      digitalWrite(ledPins[i], HIGH);
      tone(buzzerPin, 1000, 100);  // Play tone when button is pressed
      delay(300);
      digitalWrite(ledPins[i], LOW);
      noTone(buzzerPin);

      if (i == sequence[inputIndex]) {
        inputIndex++;
        if (inputIndex == sequenceLength) {
          playWinTone();
          level++;          // Increment level on successful completion
          displayLevel();   // Display the new level
          delay(1000);
          addToSequence();
          playSequence();
        }
      } else {
        handleGameOver();
      }
      delay(300);  // Debounce delay
    }
  }
}
*/
// with level and level restriction
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address (0x27 is common, but it may vary depending on your module)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define buzzer and reset button pins
const int buzzerPin = 12;     // Buzzer connected to pin 12
const int resetButtonPin = 6; // Reset button connected to pin 6

// Button and LED pin definitions
const int buttonPins[] = {2, 3, 4, 5};   // Button input pins
const int ledPins[] = {8, 9, 10, 11};    // LED output pins

// Game variables
int sequence[100];
int inputSequence[100];
int sequenceLength = 0;
int inputIndex = 0;
int level = 1;  // Track the game level

// Game states
bool gameOver = false;

// Tones for win and game over
void playWinTone() {
  tone(buzzerPin, 1000, 200);  // Play a tone of 1000 Hz for 200 ms
  delay(300);
  tone(buzzerPin, 1200, 200);
  delay(300);
  noTone(buzzerPin);
}

void playGameOverTone() {
  tone(buzzerPin, 200, 300);   // Play a low tone for 300 ms
  delay(400);
  tone(buzzerPin, 100, 300);
  delay(400);
  noTone(buzzerPin);
}

// Setup function
void setup() {
  Serial.begin(9600);
  lcd.init();             // Initialize the LCD
  lcd.backlight();        // Turn on the LCD backlight
  lcd.setCursor(0, 0);
  lcd.print("Aero Memory"); // Display the heading

  pinMode(buzzerPin, OUTPUT);
  pinMode(resetButtonPin, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  delay(2000); // Wait for 2 seconds before starting the game
  startGame();
}

// Function to start the game
void startGame() {
  sequenceLength = 0;
  inputIndex = 0;
  level = 1;        // Reset the level to 1
  gameOver = false;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Start");

  displayLevel();   // Display the current level

  Serial.println("Game Started");
  addToSequence();
  playSequence();
}

// Function to add a random LED to the sequence
void addToSequence() {
  sequence[sequenceLength] = random(0, 4);  // Generate a random number between 0 and 3
  sequenceLength++;
}

// Function to play the current sequence
void playSequence() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Watch Sequence");

  for (int i = 0; i < sequenceLength; i++) {
    int led = sequence[i];
    digitalWrite(ledPins[led], HIGH);
    tone(buzzerPin, 600, 350);  // Play tone while LED is on
    delay(400);
    digitalWrite(ledPins[led], LOW);
    noTone(buzzerPin);
    delay(200);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Your Turn");
  inputIndex = 0;  // Reset input index for the player's turn
}

// Function to handle game over
void handleGameOver() {
  gameOver = true;

  // Turn on all LEDs
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
  }

  // Display Game Over on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Over!");

  // Play game-over tone
  playGameOverTone();

  // Wait for reset button press
  while (digitalRead(resetButtonPin) == HIGH) {
    // Do nothing until reset button is pressed
  }

  // Turn off all LEDs and restart the game
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  startGame();
}

// Function to display the current level
void displayLevel() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Level: ");
  lcd.print(level);
  Serial.print("Level: ");
  Serial.println(level);
  delay(2000);  // Display the level for 2 seconds
}

// Function to display congratulations message
void displayCongratulations() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Congratulations!");
  lcd.setCursor(0, 1);
  lcd.print("You Won!");
  Serial.println("Congratulations! You Won!");

  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, 1000, 300);
    delay(500);
    noTone(buzzerPin);
  }

  // Wait for reset button press to restart the game
  while (digitalRead(resetButtonPin) == HIGH) {
    // Do nothing until reset button is pressed
  }
  
  startGame();
}

// Loop function
void loop() {
  if (gameOver) {
    handleGameOver();
    return;
  }

  if (digitalRead(resetButtonPin) == LOW) {
    startGame();
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      digitalWrite(ledPins[i], HIGH);
      tone(buzzerPin, 1000, 100);  // Play tone when button is pressed
      delay(300);
      digitalWrite(ledPins[i], LOW);
      noTone(buzzerPin);

      if (i == sequence[inputIndex]) {
        inputIndex++;
        if (inputIndex == sequenceLength) {
          playWinTone();
          
          if (level == 15) {
            displayCongratulations();  // Show congratulations message if Level 15 is completed
          } else {
            level++;          // Increment level on successful completion
            displayLevel();   // Display the new level
            delay(1000);
            addToSequence();
            playSequence();
          }
        }
      } else {
        handleGameOver();
      }
      delay(300);  // Debounce delay
    }
  }
}
