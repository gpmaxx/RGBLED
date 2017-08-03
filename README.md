# RGBLED
A basic Arduino library for 4 pronged RGB LEDs with gamma correction support and basic colour names

// Example 1

#include <RGBLED.h>  

// pins must be pwm
// Red pin = 11, Green Pin = 10, Blue pin = 10,  
// Gamma Correction  off, Invert values off (0 == LED Off, 255 == LED MAX)  
RGBLED led1(11,10,9,false,false);  

void setup()  
{  
    led1.on();             // turns LED on  
}

void loop()  
{
    led1.setColor(RED);     // RGB = 255,0,0  
    delay(1000);  
    led1.setColor(LIME);    // RGB = 0,255,0  
    delay(1000);  
    led1.setColor(BLUE);    // RGB = 0,0,255  
    delay(1000);
  led1.setColor(PURPLE);  // RGB = 128, 0, 128
  delay(1000);
  led1.gammaOn();         // Turn gamma correction mode on. Next color change will be gamma corrected
  led1.setColor(PURPLE);  // RGB = 37, 0, 37   // PURPLE values are adjusted
  delay(1000);
  led1.setColors(10,100,200);  // RGB = 0, 10, 129   // Custom values are adjusted
  led1.gammaOff();             // Turn gammm correction mode off. Next color change will not be gamma corrected
  led1.setColors(10,100,200);  // RGB = 10,100,200   // Custom values are left alone
  delay(1000);  
  led1.off();                  // RGB = 10,100,200 values preserved but led is off
  delay(1000);
  led1.on();		       // Led turned back on with previous RGB values in effect
}

// Example 2

#include <RGBLED.h>

RGBLED led1(11,10,9,true,false);   // Red pin = 11, Green Pin = 10, Blue pin = 10, Gamma correction on, Invert values off (0 == LED Off, 255 == LED MAX)

void setup()
{
 led1.on();      // turns LED on
}

void loop()
{
  for (int i = 0; i < RGBLED_NUM_COLORS; i++)
  {
    led1.setColor(i);   // As the predefined colors are just uint8_t values (e.g. MAROON = 10) they can be enumerated
    delay(1000);
  }
}  