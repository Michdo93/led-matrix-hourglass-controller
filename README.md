# LED Matrix Hourglass Controller

An embedded interactive timer featuring an LED matrix animation layout, a 1x4 keypad for command inputs (Start, Reset, Adjust), and voice/sound effects via a DFPlayer Mini.

## Components List
- 1x Arduino Nano
- 1x 1x4 Membrane Keypad (Push buttons)
- 4x 10k ohm Resistors (for pull-down button configuration)
- 1x DFPlayer Mini MP3 Module
- 1x MicroSD Card (formatted to FAT32 with numbered MP3 files like `0001.mp3`, `0002.mp3`)
- 1x 8-Ohm 1W-3W Speaker
- 1x LED Matrix display module (or discrete matrix layout)
- Breadboard and connection wires

## Wiring & Pinout
| Component | Arduino Pin / Connection | Description |
| :--- | :--- | :--- |
| Keypad Button 1 (Start) | Pin D2 | Start timer trigger |
| Keypad Button 2 (Reset) | Pin D3 | Reset timer trigger |
| Keypad Button 3 (Time +) | Pin D4 | Increment duration |
| Keypad Button 4 (Time -) | Pin D5 | Decrement duration |
| DFPlayer TX | Pin D10 (SoftwareSerial RX) | Serial command transmission |
| DFPlayer RX | Pin D11 (SoftwareSerial TX) | Serial command reception |
| Speaker | DFPlayer SPK+ / SPK- | Audio playback output |

## Configuration & Installation
1. Prepare the MicroSD card: create a folder named `mp3` and place audio files named strictly as `0001.mp3` (Start sound) and `0002.mp3` (Stop/Completion sound).
2. Install the `DFRobotDFPlayerMini` library via the Arduino IDE Library Manager.
3. Wire the 1x4 keypad with 10k ohm pull-down resistors to digital pins D2 through D5.

## Flashing & Startup
1. Open `src/HourglassController.ino` in the Arduino IDE.
2. Select your board configuration and upload the code.
3. Power on the system, press Button 1 to initiate the hourglass countdown and play the start sound. When complete, the stop sound triggers automatically.
