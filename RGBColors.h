#ifndef RGBCOLORS_H
#define RGBCOLORS_H

const uint8_t PROGMEM COLORS[][3] = {
{0,0,0}, 	 	// Black
{255,255,255},	// White
{255,0,0},		// Red
{0,255,0},		// Lime
{0,0,255},		// Blue
{255,255,0},	// Yellow
{0,255,255},	// Cyan
{255,0,255},	// Magenta
{192,192,192},	// Silver
{128,128,128},	// Gray
{128,0,0},		// Maroon
{128,128,0},	// Olive
{0,128,0},		// Green
{128,0,128},	// Purple
{0,128,128},	// Teal
{0,0,128},		// Navy
};

const uint8_t BLACK = 0;
const uint8_t WHITE = 1;
const uint8_t RED = 2;
const uint8_t LIME = 3;
const uint8_t BLUE = 4;
const uint8_t YELLOW = 5;
const uint8_t CYAN = 6;
const uint8_t MAGENTA = 7;
const uint8_t SILVER = 8;
const uint8_t GRAY = 9;
const uint8_t MAROON = 10;
const uint8_t OLIVE = 11;
const uint8_t GREEN = 12;
const uint8_t PURPLE = 13;
const uint8_t TEAL = 14;
const uint8_t NAVY = 15;

const uint8_t NUM_COLORS = 16;

#endif