#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// Software Serial for DFPlayer Mini (RX, TX)
SoftwareSerial softwareSerial(10, 11);
DFRobotDFPlayerMini audioPlayer;

// Keypad Pin Definitions (1x4 Membrane Keypad with Pull-Down Resistors)
const int buttonStartPin = 2;
const int buttonResetPin = 3;
const int buttonTimePlusPin = 4;
const int buttonTimeMinusPin = 5;

// Timer State Variables
bool isTimerRunning = false;
unsigned long timerDurationSeconds = 60; // Default 1 minute
unsigned long countdownStartTime = 0;

void setup() {
  Serial.begin(9600);
  softwareSerial.begin(9600);

  // Initialize hardware input pins
  pinMode(buttonStartPin, INPUT);
  pinMode(buttonResetPin, INPUT);
  pinMode(buttonTimePlusPin, INPUT);
  pinMode(buttonTimeMinusPin, INPUT);

  Serial.println(F("Initializing DFPlayer Mini..."));
  if (!audioPlayer.begin(softwareSerial)) {
    Serial.println(F("Initialization failed! Please check wiring and SD card."));
    while (true);
  }
  
  audioPlayer.volume(20); // Set volume level (0 to 30)
  Serial.println(F("Hourglass System Ready. Waiting for user input."));
}

void loop() {
  // Read button inputs
  if (digitalRead(buttonStartPin) == HIGH && !isTimerRunning) {
    startHourglassTimer();
  }

  if (digitalRead(buttonResetPin) == HIGH) {
    resetHourglassTimer();
  }

  // Handle active countdown logic
  if (isTimerRunning) {
    unsigned long elapsedTime = (millis() - countdownStartTime) / 1000;
    
    if (elapsedTime >= timerDurationSeconds) {
      completeHourglassTimer();
    }
  }
}

void startHourglassTimer() {
  isTimerRunning = true;
  countdownStartTime = millis();
  
  Serial.println(F("Hourglass started. Playing start audio track (0001.mp3)."));
  audioPlayer.play(1); // Play start sound
}

void resetHourglassTimer() {
  isTimerRunning = false;
  Serial.println(F("Hourglass reset manually."));
  audioPlayer.stop();
}

void completeHourglassTimer() {
  isTimerRunning = false;
  Serial.println(F("Hourglass completed! Playing stop audio track (0002.mp3)."));
  audioPlayer.play(2); // Play completion/stop sound
}
