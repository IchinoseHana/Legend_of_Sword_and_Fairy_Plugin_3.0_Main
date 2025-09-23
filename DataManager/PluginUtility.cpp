#include "stdafx.h"
#include "PluginUtility.h"

string PluginUtility::numberToString(int num)
{
	char buffer[maxBufferSizeForNumberToString];
    _itoa(num, buffer, 10);
	string temp = buffer;
	return temp;
}

int PluginUtility::stringToNumber(const string& str)
{
	return atoi(str.c_str());
}

bool PluginUtility::stringToBool(const string& str)
{
	return str == "1" ? true : false;
}