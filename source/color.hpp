#ifndef COLOR_HPP
#define COLOR_HPP

//A data transfer object is an object with the primary purpose of storing and transferring values directly, and often has minimal if any functionality

//A struct is being used as the Color object doesn't serve any purpose other than storing and transferring information
//Unsigned char are being used instead of floats because floats can't handle a restriction of numbers being between 0 and 1 without adding getters, setters and significant fucntionality.
//Adrian gave us permission to set these up as unsigned chars instead of floats, with a range of 0-255 for that reason.
struct Color
{
	unsigned char r = 122;
	unsigned char g = 122;
	unsigned char b = 122;
};

#endif