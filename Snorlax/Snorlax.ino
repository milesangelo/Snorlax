#include <IRremote.hpp>
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
const int LED_PIN = 44;
const int IR_RECEIVE_PIN = 46;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, false);
  pinMode(LED_PIN, OUTPUT);
  while (!Serial);
  Serial.println("Input 1 to Turn LED on and 2 to off");
}

int recv_command = 0;
int power_state = 0;
int hasNewCommand = 0;
void loop() {
  recv_command = 0;
  if (IrReceiver.decode()) {
    //IrReceiver.printIRResultShort(&Serial);
    //recv_command = IrReceiver.decodedIRData.command;
    if (IrReceiver.decodedIRData.command > 0) {
      hasNewCommand = 1;
    }
    //Serial.println(recv_command);
    digitalWrite(LED_PIN, HIGH);
    delay(250);
    digitalWrite(LED_PIN, LOW);
    IrReceiver.resume();
  }

 
  if (hasNewCommand == 1) {
    hasNewCommand = 0;
    
    if (recv_command == 0x45 && power_state == 0) {
      power_state = 1;
      Serial.println("Power on");
    } else if (recv_command == 0x45 && power_state == 1) {
      power_state = 0;
      Serial.println("Power off");
    }
   
    if (recv_command == 0x46) {
      Serial.println("Volume up");
    }
  }

  

  

  

  // put your main code here, to run repeatedly:
  // if (Serial.available())
  // {
  //   int state = Serial.parseInt();
  //   if (state == 1)
  //   {
  //     digitalWrite(LED_PIN, HIGH);
  //     Serial.println("Command completed LED turned ON");
  //   }
  //   if (state == 2)
  //   {
  //     digitalWrite(LED_PIN, LOW);
  //     Serial.println("Command completed LED turned OFF");
  //   }
  // }
}
