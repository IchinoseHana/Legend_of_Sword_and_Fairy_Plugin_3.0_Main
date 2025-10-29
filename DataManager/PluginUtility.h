#ifndef _PAL3_PLUGINUTILITY_H_
#define _PAL3_PLUGINUTILITY_H_

#pragma once

#define n2s(x) PluginUtility::numberToString(x)
#define n2sH(x) PluginUtility::numberToStringHex(x)
#define d2s(x) PluginUtility::doubleToString(x)
#define s2n(x) PluginUtility::stringToNumber(x)
#define s2d(x) PluginUtility::stringToDouble(x)
#define s2b(x) PluginUtility::stringToBool(x)

#include <string>

using std::string;

// Size of the buffer used to transform a number to a string.
const int maxBufferSizeForNumberToString = 128;

// MARK: Utilities
class PluginUtility
{
public:
	// Basic function
	// Transform a number to a string.
	static string numberToString(int num);
	// Transform a number to a string with a hex format.
	static string numberToStringHex(int num);
	// Transform a double to a string.
	static string PluginUtility::doubleToString(double num);
	// Transform a string to a number.
	static int stringToNumber(const string& str);
	// Transform a string to a double.
	static double stringToDouble(const string& str);
	// Transform a string to a bool. "0" -> false, other -> true.
	static bool stringToBool(const string& str);

private:
	
	PluginUtility();
	PluginUtility(const PluginUtility&);
	PluginUtility& operator = (const PluginUtility&);
	~PluginUtility();
};

// The struct of color
struct PluginColorInstance
{	
public:
	unsigned short red;
	unsigned short green;
	unsigned short blue;
	unsigned short alpha;

	// Constructor & destructor
	PluginColorInstance();
	PluginColorInstance(unsigned short red, unsigned short green, unsigned short blue, unsigned short alpha);
	~PluginColorInstance();

private:

	PluginColorInstance(const PluginColorInstance&);
	PluginColorInstance& operator = (const PluginColorInstance&);
};

#endif
