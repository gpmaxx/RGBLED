/*

MIT License

Copyright (c) 2017 Greg Lipscomb

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Date: 	April 30, 2017
By:		Greg Lipscomb - g_lipscomb@hotmail.com
Desc: 	Basic RGB LED library with gamma correction

ToDo:	Test invert functionality

*/

#ifndef RGBLED_h
#define RGBLED_h

#include <Arduino.h>
#include <RGBColors.h>

extern const PROGMEM uint8_t COLORS[][3];   // RGB triplets
extern const PROGMEM uint8_t GAMMA[];       // gamma correction mapping

class RGBLED {

public:
	// pin for the R,G & B signals of the RGB LED - must be PWM
	// gamma = true means given values for each channel will be gamma corrected
	// invertvalue = true means values will be inverted 255 - value so a provided value of 40 will set the RGB channels value to 215
	// seed = value used to seed randomisation
	RGBLED(const uint8_t rPin, const uint8_t gPin, const uint8_t bPin, bool gamma = true, bool invertValues = false);

	// Set the LEDs color to the provided RGB values.  Values will be inverted and gamma corrected as appropriate
	void setColors(const uint8_t rValue, const uint8_t gValue, const uint8_t bValue);

	// set the RGB tripplet of the LED to the provided predefined basic color as outlined in RGBColors.h
	void setColor(const uint8_t stringColor);
	void gammaOn();
	void gammaOff();
	void on();
	void off();

	// LED will be set to a random color.  If basicColorsOnly == true then only the primary colors defined in RGBColors will be used
	// otherwise all 255 x 255 x 255 = 16M combinations are possible (however the possible combinations are limited by the gamma correction "flattening out"
	// of lower values)
	void setRandomColor(const bool basicColorsOnly);

	// Every interval ms, change the LEDs color to a random color, stop after duration ms
	// iff basicColorsOnly then only the predefined colors in RGBColor.h will be used
	void colorDemo(const uint32_t duration,const uint32_t interval,const bool basicColorsOnly);
	uint8_t getRValue();  // return currect R value
	uint8_t getGValue();  // return current G value
	uint8_t getBValue();  // return current B value

	// set seed the random function so the random color functions can be used.
	// Seed can not be provided in the constructor because typically analogRead would be used to provide a seed and
	// analogRead will not work if used in a global level declaration
	void initRandom(uint32_t seed);

private:

	// Private methods
	void gammaCorrect();   											// adjust the RGB values iff gamma correction is enabled
	uint8_t gammaMap(const uint8_t value);							// return the gamma corrected value of the provided value
	void invertValues();											// adjust the RGB values iff invert valus is enabled
	uint8_t getColorPart(const uint8_t row, const uint8_t col);     // return the RGB color segment from the COLORS matrix in RGBColors.h
	void update();													// changes the LEDs displayed color iff the LED is currented illuminated

	// getter/setter methods
	uint8_t getRPin();
	uint8_t getGPin();
	uint8_t getBPin();
	void setRValue(uint8_t rValue);  // private = don't allow direct setting public access to individual RGB channels
	void setGValue(uint8_t gValue);
	void setBValue(uint8_t bValue);
	void setGamma(bool value);
	bool getGamma();
	bool getInvertValues();
	uint8_t getOffValue();

	bool getIsOn();
	void setIsOn(bool value);


	// instance vars
	uint8_t _rPin;
	uint8_t _gPin;
	uint8_t _bPin;
	uint8_t _rValue;
	uint8_t _gValue;
	uint8_t _bValue;
	bool _gamma;
	bool _invertValues;
	bool _isOn;
	uint8_t _offValue = 0;


};
#endif
