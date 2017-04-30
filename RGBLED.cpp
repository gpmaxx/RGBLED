#include "RGBLED.h"
#include <Arduino.h>
#include <Gamma.h>

/* Constructors */

RGBLED::RGBLED(const uint8_t rPin, const uint8_t gPin, const uint8_t bPin, bool gamma /* =true */,bool invertValues /*= false */)
: _rPin(rPin),_gPin(gPin),_bPin(bPin),_gamma(gamma), _invertValues(invertValues),_isOn(false)
{
	pinMode(rPin,OUTPUT);
	pinMode(gPin,OUTPUT);
	pinMode(bPin,OUTPUT);
	if (getInvertValues()) {_offValue = 255;}
}

/* Public */
void RGBLED::setColors(const uint8_t rValue, const uint8_t gValue, const uint8_t bValue)
{
	setRValue(rValue);
	setGValue(gValue);
	setBValue(bValue);
	if (getGamma()) {gammaCorrect();}
	if (getInvertValues()) {invertValues();}
	update();
}

void RGBLED::gammaOn(){ setGamma(true); update();}
void RGBLED::gammaOff(){ setGamma(false); update(); }

void RGBLED::on()
{
	setIsOn(true);
	analogWrite(getRPin(),getRValue());
	analogWrite(getGPin(),getGValue());
	analogWrite(getBPin(),getBValue());
}

void RGBLED::off()
{
	setIsOn(false);
	analogWrite(getRPin(),getOffValue());
	analogWrite(getGPin(),getOffValue());
	analogWrite(getBPin(),getOffValue());
}

void RGBLED::update()
{
	if(getIsOn())
	{
		on();
	}
}

/* Private */
void RGBLED::gammaCorrect()
{
	setRValue(gammaMap(getRValue()));
	setGValue(gammaMap(getGValue()));
	setBValue(gammaMap(getBValue()));
}

void RGBLED::invertValues()
{
	setRValue(255 - getRValue());   // magic numbers make CS professors cry
	setGValue(255 - getGValue());
	setBValue(255 - getBValue());
}

uint8_t RGBLED::gammaMap(const uint8_t value)
{
	return pgm_read_byte(&GAMMA[value]);
}

void RGBLED::initRandom(uint32_t seed)
{
	randomSeed(seed);
}

void RGBLED::setRandomColor(const bool basicColorsOnly)
{
	if (basicColorsOnly) {
		setColor(random(NUM_COLORS));
	}
	else {
		setColors(random(255),random(255),random(255));
	}
}

void RGBLED::colorDemo(const uint32_t duration, const uint32_t interval, const bool basicColorsOnly)
{
	uint32_t durationTimer = millis();
	uint32_t intervalTimer = millis();

	while ((millis() - durationTimer) < duration)
	{
		setRandomColor(basicColorsOnly);
		intervalTimer = millis();
		while ((millis() - intervalTimer) < interval) {}
	}
}

void RGBLED::setColor(const uint8_t stringColor)
{
	setColors(getColorPart(stringColor,0),getColorPart(stringColor,1),getColorPart(stringColor,2));
}

uint8_t RGBLED::getColorPart(const uint8_t row, const uint8_t col)
{
	return pgm_read_byte(&(COLORS[row][col]));
}


/* Getters & Setters */
uint8_t RGBLED::getRPin() { return _rPin; } // only set in constructor so no set method
uint8_t RGBLED::getGPin() { return _gPin; } // only set in constructor so no set method
uint8_t RGBLED::getBPin() { return _bPin; } // only set in constructor so no set method

void RGBLED::setRValue(uint8_t rValue) {_rValue = rValue;}
uint8_t RGBLED::getRValue(){return _rValue;}
void RGBLED::setGValue(uint8_t gValue) {_gValue = gValue;}
uint8_t RGBLED::getGValue(){return _gValue;}
void RGBLED::setBValue(uint8_t bValue) {_bValue = bValue;}
uint8_t RGBLED::getBValue(){return _bValue;}

void RGBLED::setGamma(bool value) {_gamma = value;}
bool RGBLED::getGamma(){return _gamma;}

bool RGBLED::getInvertValues(){return _invertValues;} // only set in constructor so no set method

uint8_t RGBLED::getOffValue(){return _offValue;} // only set in consturctor so no set method

void RGBLED::setIsOn(bool value){_isOn = value;}
bool RGBLED::getIsOn(){return _isOn;}