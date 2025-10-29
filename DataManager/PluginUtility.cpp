#include "stdafx.h"
#include "PluginUtility.h"

string PluginUtility::numberToString(int num)
{
	char buffer[maxBufferSizeForNumberToString];
    _itoa(num, buffer, 10);
	string temp = buffer;
	return temp;
}

string PluginUtility::numberToStringHex(int num)
{
	char buffer[maxBufferSizeForNumberToString];
	sprintf(buffer, "%X", num);
	string temp = buffer;
	return temp;
}

string PluginUtility::doubleToString(double num)
{
	char buffer[maxBufferSizeForNumberToString];
	sprintf(buffer, "%f", num);
	string temp = buffer;
	return temp;
}

int PluginUtility::stringToNumber(const string& str)
{
	return atoi(str.c_str());
}

double PluginUtility::stringToDouble(const string& str)
{
	return atof(str.c_str());
}

bool PluginUtility::stringToBool(const string& str)
{
	return str == "1" ? true : false;
}

PluginColorInstance::PluginColorInstance()
{
	this->red = 0;
	this->green = 0;
	this->blue = 0;
	this->alpha = 0;
}

PluginColorInstance::PluginColorInstance(unsigned short red, unsigned short green, unsigned short blue, unsigned short alpha)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

PluginColorInstance::~PluginColorInstance()
{

}