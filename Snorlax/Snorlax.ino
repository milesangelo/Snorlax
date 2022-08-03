#include <IRremote.hpp>

#define POWER_BUTTON 0x45
#define VOLUME_UP 0x46
#define VOLUME_DOWN 0x15
#define FORWARD 0x43
#define REWIND 0x44
#define PLAY_PAUSE 0x40
#define FUNC_STOP 0x47
// still need UP
#define DOWN 0x07
#define EQUALIZE 0x19
#define STOP_REPEAT 0xD
#define ZERO 0x16
// do the rest...
// 0 ....9 = [0x16, 0xC, 0x18, 0x5E, 0x8, 0x1C, 0x5A, 0x42, 0x52, 0x4A]
const int LED_PIN = 44;
const int IR_RECEIVE_PIN = 46;

void flashLed() {
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);
}

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, false);
  pinMode(LED_PIN, OUTPUT);
  while (!Serial);
  Serial.println("Input 1 to Turn LED on and 2 to off");
}

int power_state = 0;
int hasNewCommand = 0;

void loop() {
  
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.command > 0) {
      hasNewCommand = 1;
    }
    flashLed();
    IrReceiver.resume();
  }

  if (hasNewCommand == 1) {    
    switch (IrReceiver.decodedIRData.command) {
      case POWER_BUTTON:
      {
        if (power_state == 0) {
          power_state = 1;
          Serial.println("Power on");
        } else if (power_state == 1) {
          power_state = 0;
          Serial.println("Power off");
        }
        break;
      }
      case VOLUME_UP:
      {
        Serial.println("Volume up");
        break;
      }
      case VOLUME_DOWN:
      {
        Serial.println("Volume down");
        break;
      }
      case REWIND:
      {
        Serial.println("Rewinding...");
        break;
      }
      case FORWARD:
      {
        Serial.println("Forwarding...");
        break;
      }
      default:
        break;
    }
    
    hasNewCommand = 0;
  }
}
