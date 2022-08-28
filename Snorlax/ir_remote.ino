#include <IRremote.hpp>

#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262

//power button = 0x45
//vol + =0x46
//vol - =0x15
// func/stop = 0x47
// rewind = 0x44
// play pause = 0x40
// forward = 0x43
// down = 0x07
// EQ = 0x19
// st/ rept = 0xD
// 0 ....9 = [0x16, 0xC, 0x18, 0x5E, 0x8, 0x1C, 0x5A, 0x42, 0x52, 0x4A]

const int SPEAKER_PIN = 11;
const int LED_PIN = 44;
const int IR_RECEIVE_PIN = 46;

void setup() {
    // Serial.begin(9600);
    // IrReceiver.begin(IR_RECEIVE_PIN, false);
    // pinMode(LED_PIN, OUTPUT);
    // while (!Serial);
    // Serial.println("Input 1 to Turn LED on and 2 to off");
    
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
}

int recv_command =  0;
int power_state = 0;
int hasNewCommand = 0;

void loop() {
    // recv_command = 0;
    // if (IrReceiver.decode()) {
    //     if (IrReceiver.decodedIRData.command > 0) {
    //         hasNewCommand = 1;
    //         digitalWrite(LED_PIN, HIGH);
    //         delay(250);
    //         digitalWrite(LED_PIN, LOW);
    //         recv_command = IrReceiver.decodedIRData.command;
    //     }

    //     IrReceiver.resume();
    // }

    // if (hasNewCommand == 1) {
    //     hasNewCommand = 0;
    //     if (recv_command == 0x45 && power_state == 0) {
    //         power_state = 1;
    //         Serial.println("Power on");
    //     } else if (recv_command == 0x45 && power_state == 1) {
    //         power_state = 0;
    //         Serial.println("Power off");
    //     }

    //     if (recv_command == 0x46) {
    //         Serial.println("Volume up");
    //     }
    // }
}
