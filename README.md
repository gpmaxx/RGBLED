# RGBLED
A small Arduino library/wrapper for 4 pronged RGB LEDs with gamma correction support and basic colour names.  
Invert function  support common cathod and common annode. Input pins must be PWM.  
  
ToDo:  Some further testing of the invert functions 


Example 1

```cpp
#include <RGBLED.h>  

// pins must be pwm  
// Red pin = 11, Green Pin = 10, Blue pin = 10,  
// Gamma Correction  off, Invert values off (0 == LED Off, 255 == LED MAX)  
RGBLED led1(11,10,9,false,false);  

void setup() {
 led1.on();             // turns LED on
}

void loop2() {
  led1.setColor(RED);     	// RGB = 255,0,0
  delay(1000);
  led1.setColor(LIME);    	// RGB = 0,255,0
  delay(1000);
  led1.setColor(BLUE);    	// RGB = 0,0,255
  delay(1000);
  led1.setColor(PURPLE);  	// RGB = 128, 0, 128
  delay(1000);
  led1.gammaOn();         	// Turn gamma correction mode on. Next color change will be gamma corrected
  led1.setColor(PURPLE);  	// RGB = 37, 0, 37
  delay(1000);
  led1.setColors(10,100,200);  	// RGB = 0, 10, 129
  led1.gammaOff();             	// Turn gammm correction mode off. Next color changje will not be gamma corrected
  led1.setColors(10,100,200);  	// RGB = 10,100,200
  delay(1000);  
  led1.off();                  	// RGB = 10,100,200 but LED is off
  delay(1000);
  led1.on();
}
```

Example 2

```cpp
#include <RGBLED.h>

// Gamma correction on, Invert values off 
RGBLED led1(11,10,9,true,false);   

void setup() {
 led1.on();      // turns LED on
}

void loop() {
  for (int i = 0; i < RGBLED_NUM_COLORS; i++)
  {
    // As the predefined colors are just uint8_t values (e.g. MAROON = 10) they can be enumerated
    led1.setColor(i);   
    delay(1000);
  }
}
```
