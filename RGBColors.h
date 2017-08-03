// Reference: http://www.rapidtables.com/web/color/RGB_Color.htm

#ifndef RGBCOLORS_H
#define RGBCOLORS_H

const uint8_t RGBLED_NUM_COLORS = 24;

const uint8_t PROGMEM COLORS[RGBLED_NUM_COLORS][3] = {
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
{165,42,42},	// Brown
{220,20,60},	// Crimson
{255,165,0},	// Orange
{238,130,238},	// Violet
{75,0,130},		// Indigo
{255,192,203},	// Pink
{210,180,140},	// Tan
{160,82,45},	// Sienna

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
const uint8_t BROWN = 16;
const uint8_t CRIMSON = 17;
const uint8_t ORANGE = 18;
const uint8_t VIOLET = 19;
const uint8_t INDIGO = 20;
const uint8_t PINK = 21;
const uint8_t TAN = 22;
const uint8_t SIENNA = 23;

#endif