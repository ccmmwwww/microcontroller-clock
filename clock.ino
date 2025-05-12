#include <Arduino.h>
#include <TM1637Display.h>
#define CLK 2
#define DIO 3
#define sec 1000
#define min 60000
#define min2 60007
const uint8_t donE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,  // d
  SEG_G | SEG_C | SEG_D | SEG_E,          // o
  SEG_C | SEG_E | SEG_G,                  // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G   // E
};
TM1637Display display(CLK, DIO);
void setup() {
}
void loop() 
{
  int m = 0, h = 1100;
  display.setBrightness(7, true); // range from 0-7
  while (1) 
  {
    display.showNumberDecEx(h + m, 0b11100000, false);
    delay(min2);
    m++;
    if (m == 60) 
    {
      m = m - 60;
      h = h + 100;
      if (h == 1300) 
      {
        h = 100;
      }
    }
  }
  display.setSegments(donE);
}
// Ideas to add:
// Auto brightness (goes to high at some point and low at another)
// Add temp from a sensor? (On another display with the date maybe?)
// Add date? and year for leap years? (but maybe don't show year)
// Buttons to change time and date?
// Build a case or 3D print one