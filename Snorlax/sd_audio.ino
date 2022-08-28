#include <SD.h>

// #include <FastPWMdac.h>
// const byte dacPin = 11;
// FastPWMdac fastPWMdac;

#include "SD.h"
void setup()
{ 
  //analogWrite(dacPin1, 127); // analogWrite is SLOW with period 490Hz
  //fastPWMdac.init(dacPin, 10);

  
}
void loop()
{

} 
//   fastPWMdac.analogWrite10bit(random(1023));
//   delay(1);

//   // fastPWMdac.init(dacPin, 8); // initialization for 8 bit resolution
//   // for(int i=0; i<256; i++) // use byte because of 8 bit resolution
//   // { 
//   //   fastPWMdac.analogWrite8bit(i); // sawtooth output, period = 31.25Khz
//   //   delay(1);
//   // }
//   // fastPWMdac.init(dacPin, 10); // initialization for 10 bit resolution
//   // for(int i=1023; i>=0; i--)
//   // { 
//   //   fastPWMdac.analogWrite10bit(i); // sawtooth output, period = 7.8Khz
//   //   delay(1);
//   // }
// }
